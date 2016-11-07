export CC=/usr/bin/clang-3.8
export CXX=/usr/bin/clang++-3.8
export AFL_CC=/usr/bin/clang-3.8
export AFL_CXX=/usr/bin/clang++-3.8
rm -rf build
mkdir build
cd build
CXX=/home/pc022838/afl-2.35b/afl-clang-fast++
cmake -D CMAKE_CXX_COMPILER=/home/inhuman/afl-2.33b/afl-clang-fast++ -std=gnu++03 ../example/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
