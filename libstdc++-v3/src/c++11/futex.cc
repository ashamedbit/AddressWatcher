// futex -*- C++ -*-

// Copyright (C) 2015-2020 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

#include <bits/atomic_futex.h>
#ifdef _GLIBCXX_HAS_GTHREADS
#if defined(_GLIBCXX_HAVE_LINUX_FUTEX) && ATOMIC_INT_LOCK_FREE > 1
#include <chrono>
#include <climits>
#include <syscall.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <debug/debug.h>

#ifdef _GLIBCXX_USE_CLOCK_GETTIME_SYSCALL
#include <unistd.h>
#include <sys/syscall.h>
#endif

// Constants for the wait/wake futex syscall operations
const unsigned futex_wait_op = 0;
const unsigned futex_wait_bitset_op = 9;
const unsigned futex_clock_monotonic_flag = 0;
const unsigned futex_clock_realtime_flag = 256;
const unsigned futex_bitset_match_any = ~0;
const unsigned futex_wake_op = 1;

namespace
{
  std::atomic<bool> futex_clock_realtime_unavailable;
  std::atomic<bool> futex_clock_monotonic_unavailable;
}

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  bool
  __atomic_futex_unsigned_base::_M_futex_wait_until(unsigned *__addr,
      unsigned __val,
      bool __has_timeout, chrono::seconds __s, chrono::nanoseconds __ns)
  {
    if (!__has_timeout)
      {
	// Ignore whether we actually succeeded to block because at worst,
	// we will fall back to spin-waiting.  The only thing we could do
	// here on errors is abort.
	int ret __attribute__((unused));
	ret = syscall (SYS_futex, __addr, futex_wait_op, __val, nullptr);
	__glibcxx_assert(ret == 0 || errno == EINTR || errno == EAGAIN);
	return true;
      }
    else
      {
	if (!futex_clock_realtime_unavailable.load(std::memory_order_relaxed))
	  {
	    struct timespec rt;
	    rt.tv_sec = __s.count();
	    rt.tv_nsec = __ns.count();
	    if (syscall (SYS_futex, __addr,
			 futex_wait_bitset_op | futex_clock_realtime_flag,
			 __val, &rt, nullptr, futex_bitset_match_any) == -1)
	      {
		__glibcxx_assert(errno == EINTR || errno == EAGAIN
				|| errno == ETIMEDOUT || errno == ENOSYS);
		if (errno == ETIMEDOUT)
		  return false;
		if (errno == ENOSYS)
		  {
		    futex_clock_realtime_unavailable.store(true,
						    std::memory_order_relaxed);
		    // Fall through to legacy implementation if the system
		    // call is unavailable.
		  }
		else
		  return true;
	      }
	    else
	      return true;
	  }

	// We only get to here if futex_clock_realtime_unavailable was
	// true or has just been set to true.
	struct timeval tv;
	gettimeofday (&tv, NULL);
	// Convert the absolute timeout value to a relative timeout
	struct timespec rt;
	rt.tv_sec = __s.count() - tv.tv_sec;
	rt.tv_nsec = __ns.count() - tv.tv_usec * 1000;
	if (rt.tv_nsec < 0)
	  {
	    rt.tv_nsec += 1000000000;
	    --rt.tv_sec;
	  }
	// Did we already time out?
	if (rt.tv_sec < 0)
	  return false;

	if (syscall (SYS_futex, __addr, futex_wait_op, __val, &rt) == -1)
	  {
	    __glibcxx_assert(errno == EINTR || errno == EAGAIN
			     || errno == ETIMEDOUT);
	    if (errno == ETIMEDOUT)
	      return false;
	  }
	return true;
      }
  }

  bool
  __atomic_futex_unsigned_base::_M_futex_wait_until_steady(unsigned *__addr,
      unsigned __val,
      bool __has_timeout, chrono::seconds __s, chrono::nanoseconds __ns)
  {
    if (!__has_timeout)
      {
	// Ignore whether we actually succeeded to block because at worst,
	// we will fall back to spin-waiting.  The only thing we could do
	// here on errors is abort.
	int ret __attribute__((unused));
	ret = syscall (SYS_futex, __addr, futex_wait_op, __val, nullptr);
	__glibcxx_assert(ret == 0 || errno == EINTR || errno == EAGAIN);
	return true;
      }
    else
      {
	if (!futex_clock_monotonic_unavailable.load(std::memory_order_relaxed))
	  {
	    struct timespec rt;
	    rt.tv_sec = __s.count();
	    rt.tv_nsec = __ns.count();

	    if (syscall (SYS_futex, __addr,
			 futex_wait_bitset_op | futex_clock_monotonic_flag,
			 __val, &rt, nullptr, futex_bitset_match_any) == -1)
	      {
		__glibcxx_assert(errno == EINTR || errno == EAGAIN
				 || errno == ETIMEDOUT || errno == ENOSYS);
		if (errno == ETIMEDOUT)
		  return false;
		else if (errno == ENOSYS)
		  {
		    futex_clock_monotonic_unavailable.store(true,
						    std::memory_order_relaxed);
		    // Fall through to legacy implementation if the system
		    // call is unavailable.
		  }
		else
		  return true;
	      }
	  }

	// We only get to here if futex_clock_monotonic_unavailable was
	// true or has just been set to true.
	struct timespec ts;
#ifdef _GLIBCXX_USE_CLOCK_GETTIME_SYSCALL
	syscall(SYS_clock_gettime, CLOCK_MONOTONIC, &ts);
#else
	clock_gettime(CLOCK_MONOTONIC, &ts);
#endif
	// Convert the absolute timeout value to a relative timeout
	struct timespec rt;
	rt.tv_sec = __s.count() - ts.tv_sec;
	rt.tv_nsec = __ns.count() - ts.tv_nsec;
	if (rt.tv_nsec < 0)
	  {
	    rt.tv_nsec += 1000000000;
	    --rt.tv_sec;
	  }
	// Did we already time out?
	if (rt.tv_sec < 0)
	  return false;

	if (syscall (SYS_futex, __addr, futex_wait_op, __val, &rt) == -1)
	  {
	    __glibcxx_assert(errno == EINTR || errno == EAGAIN
			     || errno == ETIMEDOUT);
	    if (errno == ETIMEDOUT)
	      return false;
	  }
	return true;
      }
  }

  void
  __atomic_futex_unsigned_base::_M_futex_notify_all(unsigned* __addr)
  {
    // This syscall can fail for various reasons, including in situations
    // in which there is no real error.  Thus, we don't bother checking
    // the error codes.  See the futex documentation and glibc for background.
    syscall (SYS_futex, __addr, futex_wake_op, INT_MAX);
  }

_GLIBCXX_END_NAMESPACE_VERSION
}
#endif // defined(_GLIBCXX_HAVE_LINUX_FUTEX) && ATOMIC_INT_LOCK_FREE > 1
#endif // _GLIBCXX_HAS_GTHREADS
