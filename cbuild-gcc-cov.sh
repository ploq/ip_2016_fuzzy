AFL_CC=gcc
AFL_CXX=g++
rm -rf build_gcc_cov
mkdir build_gcc_cov
cd build_gcc_cov
CC=~/afl-2.35b/afl-gcc CXX=~/afl-2.35b/afl-g++ cmake -DCMAKE_CXX_FLAGS=" -g -fsanitize=address -fprofile-arcs -ftest-coverage" \
-DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address -fprofile-arcs -ftest-coverage" ../flat/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
AFL_HARDEN=1 AFL_USE_ASAN=1 make
