AFL_CC=clang
AFL_CXX=clang++
rm -rf build
mkdir build
cd build
CC=~/afl-2.35b/afl-clang-fast CXX=~/afl-2.35b/afl-clang-fast++ cmake ../flat/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
