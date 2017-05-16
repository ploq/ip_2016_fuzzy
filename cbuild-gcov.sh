AFL_CC=clang
AFL_CXX=clang++
rm -rf build_gcov
mkdir build_gcov
cd build_gcov
CC=~/afl-2.35b/afl-clang-fast CXX=~/afl-2.35b/afl-clang-fast++ cmake -DCMAKE_CXX_FLAGS=" -g -fprofile-arcs -ftest-coverage" \
-DCMAKE_EXE_LINKER_FLAGS="-fprofile-arcs -ftest-coverage" ../flat/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
