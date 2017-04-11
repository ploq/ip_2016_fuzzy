AFL_CC=clang
AFL_CXX=clang++
rm -rf build
mkdir build
cd build
CC=/home/oscho707/afl-2.35b/afl-clang-fast CXX=/home/oscho707/afl-2.35b/afl-clang-fast++ cmake -std=c++11 ../flat/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
