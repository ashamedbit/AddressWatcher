//===-- sanitizer_watchaddrfileio.cpp ----------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file is shared between all the Sanitizer
// run-time libraries.
//===----------------------------------------------------------------------===//

#include "sanitizer_common.h"
#include "sanitizer_stacktrace.h"
#include "sanitizer_watchaddrfileio.h"


namespace __sanitizer {

    bool WriteUptr(uptr x)
    {
        char c[sizeof(uptr)*2+2];
        c[sizeof(uptr)*2]='\n';
        c[sizeof(uptr)*2+1]='\0';

        int j = sizeof(uptr)*2-1;
        for (int i=0;i<sizeof(uptr)*2;i++)
        {
            c[j]= (x & 0xf) + 48;

            if (c[j]>=58)
               c[j]=c[j]+39;

            x=(x>>4);
            j--;
        }

        WatchAddrRawWrite(c);
        return true;
    }

    bool WriteWatchAddr(StackTrace* s)
    {
        // Can be used when there is no last use during a run
        if (s == nullptr)
        {
            WriteUptr(0);
            return true;
        }

        WriteUptr(s->size);

        for (int i=0; i<(s->size); i++)
        {
            WriteUptr(s->trace[i]);
        }
        return true;
    }
    
    bool WriteWatchAddr(BufferedStackTrace* s)
    {
        // Can be used when there is no last use during a run
        if (s == nullptr || s->size == 0)
        {
            WriteUptr(0);
            return true;
        }

        WriteUptr(s->size);

        for (int i=0; i<(s->size); i++)
        {
            WriteUptr(s->trace_buffer[i]);
        }
        return true;
    }

    bool WriteExecutionTrace(ExecutionTrace* p)
    {
        // Can be used when there is no last use during a run
        if (p == nullptr || p-> trace == nullptr || p->len == 0)
        {
            WriteUptr(0);
            return true;
        }

        int len = p->len;
        BufferedStackTrace* trace = p->trace;

        WriteUptr(uptr(len));
        
        for (int i=0; i < p->len; i++)
        {
            BufferedStackTrace* s = &(trace[i]);
            WriteWatchAddr(s);
        }
        return true;
    }

    bool WriteExecutionProfile(ExecutionProfile* p)
    {
        if (p == nullptr || p->exec_profile == nullptr || p->len == 0)
        {
            WriteUptr(0);
            return true;
        }

        int len = int(p->len);
        ExecutionTrace* exec_profile = p->exec_profile;
        

        WriteUptr(len);
        for (int j=0; j<len; j++)
        {
            ExecutionTrace* e = &(exec_profile[j]);
            WriteExecutionTrace(e);
        }
    }

    class AddrWatch {

    public:

        const static int maxwatch = 100;
        const static int maxexecutionlen = 10;
        BufferedStackTrace watchstack[maxwatch];
        ExecutionProfile lastusestack[maxwatch];
        BufferedStackTrace* sortedstack[maxwatch];
        bool foundthisrun[maxwatch] = {false};
        int bspos = 0;

        ExecutionProfile* GetExecutionProfile(int pos) {
            return &(lastusestack[pos]);
        }

        BufferedStackTrace* GetStack(int pos) {
            return &(watchstack[pos]);
        }

        BufferedStackTrace* InsertNewStack() {
            return GetStack(bspos++);
        }

        int GetSize(){
            return bspos;
        }

        void SetStackWrittenToWatchlist(int pos) {
            foundthisrun[pos]=1;
        }


        AddrWatch() {
        }

        ~AddrWatch() {
            // Write all stacks that we have tracked in this run to Watchlist
            DumpStacks();

            // Write Malloc stacks that were not found in this run to Address Watcher Watchlist
            for (int i=0; i<bspos; i++)
                if (foundthisrun[i] == false)
                {
                    WriteWatchAddr(&watchstack[i]);
                    WriteExecutionProfile(&lastusestack[i]);
                }
        }

        bool static CompareBufferedStackTrace(BufferedStackTrace* x, BufferedStackTrace* y);
        bool static CompareStackTrace(StackTrace* x, BufferedStackTrace* y);
        bool static EqualBufferedStackTrace(BufferedStackTrace* x, BufferedStackTrace* y);
        bool static EqualBufferedStackTrace(StackTrace* x, BufferedStackTrace* y);
        void InitandSort();
        uptr inline ReadUptr(char** c);
        void inline ReadStack(BufferedStackTrace* s, char** c);
        bool ReadWatchAddr();
        void ReadExecutionTrace(ExecutionTrace* p, char** c);
        void ReadExecutionProfile(ExecutionProfile* p, char** c);
        int IsStackPresent(BufferedStackTrace* s);
        int IsStackPresent(StackTrace* s);
    };

    AddrWatch addrwatch;

    bool AddrWatch::EqualBufferedStackTrace (BufferedStackTrace* x, BufferedStackTrace* y)
    {
        if (x->size != y->size)
           return false;

        // Discard top and bottom line
        for (int i=1;i<(x->size)-1;i++)
            if (x->trace_buffer[i] != y->trace_buffer[i])
                return false;

        return true;
    }

    bool AddrWatch::EqualBufferedStackTrace (StackTrace* x, BufferedStackTrace* y)
    {
        if (x->size != y->size)
           return false;

        // Discard top and bottom line
        for (int i=1;i<(x->size)-1;i++)
            if (x->trace[i] != y->trace_buffer[i])
                return false;

        return true;
    }

    bool AddrWatch::CompareBufferedStackTrace(BufferedStackTrace* x, BufferedStackTrace* y)
    {
        if (x->size < y->size)
            return true;

        if (x->size > y->size)
            return false;

        // Discard top and bottom line
        for(int i=1; i<(x->size)-1 ;i++)
        {
            if (x->trace_buffer[i] == y->trace_buffer[i])
                continue;

            if (x->trace_buffer[i] < y->trace_buffer[i])
                return true;

            // x Greater
            return false;
        }

        // Equal Stacktraces. No need to swap
        return true;
    }

    bool AddrWatch::CompareStackTrace(StackTrace* x, BufferedStackTrace* y)
    {
        if (x->size < y->size)
            return true;

        if (x->size > y->size)
            return false;

        // Discard top and bottom line
        for(int i=1; i<(x->size)-1 ;i++)
        {
            if (x->trace[i] == y->trace_buffer[i])
                continue;

            if (x->trace[i] < y->trace_buffer[i])
                return true;

            // x Greater
            return false;
        }

        // Equal Stacktraces. No need to swap
        return true;
    }


    // Binary Search our list of StackTrace pointers
    int AddrWatch::IsStackPresent(BufferedStackTrace* s)
    {
        int high = GetSize()-1;
        int low = 0;
        
        while (high >= low)
        {
            int mid = (high+low)/2;
            BufferedStackTrace* midstack = sortedstack[mid];

            if (EqualBufferedStackTrace(s,midstack))
            {
                return (midstack-&watchstack[0]);
            }
            else if (CompareBufferedStackTrace(s,midstack))
                high = mid-1;
            else
                low = mid+1;

        }
        return -1;
    }

    // Binary Search our list of StackTrace pointers
    int AddrWatch::IsStackPresent(StackTrace* s)
    {
        int high = GetSize()-1;
        int low = 0;
        
        while (high >= low)
        {
            int mid = (high+low)/2;
            BufferedStackTrace* midstack = sortedstack[mid];

            if (EqualBufferedStackTrace(s,midstack))
            {
                //Printf("The value of difference is %zu \n",midstack-&watchstack[0]);
                //Printf("The value of size is %zu \n",sizeof(watchstack[0]));
                //midstack->Print();
                //Printf("End of comparison\n");
                return (midstack-&watchstack[0]);
            }
            else if (CompareStackTrace(s,midstack))
                high = mid-1;
            else
                low = mid+1;

        }
        return -1;
    }

    void AddrWatch::InitandSort()
    {
        for(int i=0; i<bspos; i++)
            sortedstack[i] = GetStack(i);

        Sort(sortedstack,(uptr)bspos,CompareBufferedStackTrace);
    }

    uptr inline AddrWatch::ReadUptr(char** c)
    {
        uptr res=0;
        for (int j = 0; j <= sizeof(uptr)*2-1; j++)
        {
            int val=((*c)[j] & 0xff);

            if (val>=97)
                val=val-87;
            else
                val=val-48;

            res =res | val;

            if (j != sizeof(uptr)*2-1)
                res = res<<4;
        }

        // There is also a new line here which we dont care to take in
        *c=*c+sizeof(uptr)*2+1;
        return res;
    }

    void inline AddrWatch::ReadStack(BufferedStackTrace* s, char** c)
    {
        s->size = ReadUptr(c);

        for (uptr k=0;k<s->size;k++)
        {
            s->trace_buffer[k] = ReadUptr(c);
        }
    }

    void AddrWatch::ReadExecutionTrace(ExecutionTrace* p, char** c)
    {
        p->len = ReadUptr(c);
        BufferedStackTrace* trace = p->trace;

        for (int i=0; i < p->len; i++)
        {
            BufferedStackTrace* s = &(trace[i]);
            ReadStack(s, c);
        }
    }

    void AddrWatch::ReadExecutionProfile(ExecutionProfile* p, char** c)
    {
        p->len = ReadUptr(c);
        ExecutionTrace* exec_profile = p->exec_profile;

        for (int i=0; i < p->len; i++)
        {
            ExecutionTrace* s = &(exec_profile[i]);
            ReadExecutionTrace(s, c);
        }
    }

    bool AddrWatch::ReadWatchAddr()
    {
        char* c;
        uptr csize = 0;
        uptr read_len = 0;
        // The maximum bytes to read from our Address Watcher report.
        // This value is calculated from the maximum number of malloc stacks we're allowed to track
        // Multiplying by 2: for each malloc stack, there is a last use stack
        // Each line of a stack has 16 bytes
        // Every stack has a maximum of kStackTraceMax +1 lines including the length header.
        // We add 1 finally for the first line of the report: last built time for the binary.
        uptr max_len = (maxwatch*2*(12+1)*16)+1;
        bool opened = ReadAddrReportToBuffer(&c,&csize,&read_len,max_len);

        // If not created write the correct compile date and sign off 
        if (!opened)
            return false;

        char* p=c;

        uptr compile_time = ReadUptr(&p);
 
        // If Binary recompiled don't read this data!!
        if (CheckIfBinaryRecompiled(compile_time))
            return false;

        int scannedstacks=0;
        while (*p)
        {
            BufferedStackTrace* s = this->InsertNewStack();
            ReadStack(s,&p);

            ExecutionProfile* ls = this->GetExecutionProfile(scannedstacks);
            ReadExecutionProfile(ls,&p);
            scannedstacks++;
        }
        return true;
    }

    uptr CheckIfBinaryRecompiled(uptr time)
    {
        static uptr storedcompiletime = 0;

        if (time>=storedcompiletime)
        {
            storedcompiletime=time;
            return 0;
        }

        return storedcompiletime;
    }

    void InitializeWatchlist()
    {
        static bool time_stamp_written_to_report = 0;

        // Read addresses to watch from file
        if (addrwatch.ReadWatchAddr())
        {
            // Create sorted array of stacktraces through pointers
            addrwatch.InitandSort();
        }

        // Write the correct compile time for successive binary runs.
        if (time_stamp_written_to_report == 0)
        {
           time_stamp_written_to_report = 1;
           WriteUptr(CheckIfBinaryRecompiled(0));
        }
    }

    bool IsAddrToWatch(BufferedStackTrace *s)
    {
        int pos = addrwatch.IsStackPresent(s); 
        if (pos == -1)
            return false;

        return true;
    }

    BufferedStackTrace* MergeLastUse(BufferedStackTrace* x, BufferedStackTrace* y)
    {
        if ((x != nullptr) && (x->size<2))
            x=nullptr;

        if ((y != nullptr) && (y->size<2))
            y=nullptr;


        if ((x == nullptr) && (y==nullptr))
            return nullptr;

        if (x==nullptr)
            return y;

        if (y==nullptr)
            return x;

        int xbottom = x->size-2;
        int ybottom = y->size-2;

        while ((xbottom >= 0) && (ybottom >= 0))
        {
            if (x->trace_buffer[xbottom] > y->trace_buffer[ybottom])
            {
                return x;
            }

            if (x->trace_buffer[xbottom] < y->trace_buffer[ybottom])
            {
                return y;
            }

            xbottom--;
            ybottom--;
        }

        // At this point both stacks are equal
        return x;
    }

    bool IsSubsequence(ExecutionTrace* x, ExecutionProfile* y)
    {
        int seq_len = x->len;

        for (int i=0; i< y->len; i++)
        {
            ExecutionTrace* e = &(y->exec_profile[i]);
            if (e->len < seq_len)
            {
                continue;
            }
            int seq_index = 0;
            int j = 0;
            while (seq_index<seq_len && j<e->len)
            {
                BufferedStackTrace* b1 = &(e->trace[j]);
                BufferedStackTrace* b2 = &(x->trace[seq_index]);
                if (AddrWatch::EqualBufferedStackTrace(b1, b2) == true)
                {
                    j++;
                    seq_index++;
                }
                else
                {
                    j++;
                }
            }
            if (j == e->len && seq_index == seq_len)
            {
                // Is a subsequence
                return true;
            }
        }
        // Not a subsequence
        return false;
    }

    ExecutionProfile* MergeProfile(ExecutionTrace* x, ExecutionProfile* y)
    {
        if (y == nullptr)
            return nullptr;
        if (x == nullptr || x->len == 0)
            return y;
        
        if (IsSubsequence(x,y) == true)
        {
            return y;
        }

        int len = y->len;
        ExecutionTrace* exec_profile = y->exec_profile;

        ExecutionTrace* modify = &(exec_profile[len]);
        y->len = y->len + 1;
        internal_memcpy(modify->trace, x->trace, sizeof(modify->trace));
        modify->len = x->len;
        return y;
    }

    void UpdateWatchlist(StackTrace* mallocstack, ExecutionTrace* tracethisrun)
    {
        Printf("AddressWatcher tracking the followed leak:\n");

        // First write the malloc stack as is to Watchlist
        WriteWatchAddr(mallocstack);
        mallocstack->Print();

        // Execution Profile over all previous runs. We have already read this info from the watchlist.
        // Accessing this now for given malloc stack.
        ExecutionProfile* profile = nullptr;

        int pos = addrwatch.IsStackPresent(mallocstack);

        // Mark this object as written during this run.
        // We don't want to write it to watchlist again.
        addrwatch.SetStackWrittenToWatchlist(pos);

        if (pos != -1)
           profile = addrwatch.GetExecutionProfile(pos);
           //retmallocstack = addrwatch.GetStack(pos);

        //Printf("AddressWatcher malloc stack :\n");
        //retmallocstack->Print();

        //Printf("AddressWatcher prevlast use :\n");
        //prevlastuse->Print();

        // BufferedStackTrace* mergedlastuse = MergeLastUse(lastusethisrun, prevlastuse);
        ExecutionProfile* mergedprofile = MergeProfile(tracethisrun, profile);

        if (mergedprofile && mergedprofile->len > 0)
        {
        
           Printf("The last read/write to this leaked memory over all runs happened at:\n");
           (mergedprofile)->PrintLastUse();
           
            if (mergedprofile == nullptr || mergedprofile->exec_profile == nullptr || mergedprofile->len == 0)
            {
                WriteUptr(0);
            }
            int len = int(mergedprofile->len);
            ExecutionTrace* exec_profile = mergedprofile->exec_profile;
            WriteUptr(len);
           
            for( int j=0; j<len; j++)
            {
                ExecutionTrace* e = &(exec_profile[j]);
                WriteExecutionTrace(e);
            }
            //    WriteExecutionProfile(mergedprofile);
        }
        else
        {
           // malloc stack is last use itself for this run.
           // Instead of storing something let's write 0.
           WriteUptr(0);
        }
        Printf("\n");
    }

    void StoreNewLeak(StackTrace* mallocstack)
    {
        int pos = addrwatch.IsStackPresent(mallocstack);

        if (pos != -1)
        {
            // Leaked object exists in database
            // Must have already been stored so do nothing
            return;
        }

        // Leaked object is new: Has not been seen in Watchlist
        WriteWatchAddr(mallocstack);
        // malloc stack is last use itself for this run.
        // Instead of storing something let's write 0.
        WriteUptr(0);
    }



}
