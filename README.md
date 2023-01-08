# AddressWatcher
Memory leak bugs are a major problem in C/C++ programs, which occur when memory objects are not deallocated. Developers need to manually deallocate these objects to prevent memory leaks.

AddressWatcher is a dynamic tool that proposes fix locations for such memory leaks. AddressWatcher employs the existing infrastructure of well-known sanitizer-based tools (i.e., ASAN and LSAN) to perform a light-weight compile instrumentation in the program. Then, AddressWatcher utilizes the instrumentation during the program execution to watch and track memory leaks address. For each leak, AddressWatcher tracks possible execution paths that a leaked object passes through, and collects all stack traces where the leaked object is used. Finally, a stack that involves the deepest point in the program flow is suggested as a potential fix location for the leak. We develop a tool prototype for our framework (i.e., AddressWatcher).


Instructions to build:
1. For Debian based system including Ubuntu, Install libgmp-dev, libmpfr-dev and libmpc-dev packages. For RPM based system including Fedora and SUSE, install gmp-devel, and libmpc-devel(mpc-devel on SUSE) packages. This is a dependecy for the build.
2. Next create a new directory called build/ which is not a subdirectory of AddressWatcher
3. Change directory to build/
4. run /path/to/AddressWatcher/configure --prefix=/path/to/compiled/binaries --enable-languages=c,c++ --disable-bootstrap --disable-multilib
5. make -j4
6. make install
7. Check compiled binaries of gcc in /path/to/compiled/bin

To use the new compiled binaries with AddressWatcher mode on a C program test.c follow these steps:
1. Change directory to test program
2. export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/compiled/binaries/lib64
3. export ASAN_OPTIONS="log_path=/path/to/test.c/asan:halt_on_error=0:detect_leaks=1:address_watcher=1"
4. /path/to/compiled/binaries/bin/gcc -fsanitize=address test.c
5. Run the compiled binary twice to recieve AddressWatcher report in same directory.


Demo youtube link:
https://www.youtube.com/watch?v=cGuefW925X4
