rm -rf build
mkdir build
cd build
CXX=/home/pc022838/afl-2.35b/afl-clang-fast++
cmake -D CMAKE_CXX_COMPILER=/home/pc022838/afl-2.35b/afl-clang-fast++ -std=gnu++03 ../example/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
