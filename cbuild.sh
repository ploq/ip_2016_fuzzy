AFL_CC=gcc
AFL_CXX=g++
rm -rf build
mkdir build
cd build
CC=~/afl-2.35b/afl-gcc CXX=~/afl-2.35b/afl-g++ cmake ../flat/ -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON  -DCMAKE_CXX_FLAGS=" -g -fsanitize=address"
AFL_HARDEN=1 AFL_USE_ASAN=1 make
