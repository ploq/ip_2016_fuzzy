rm -rf build
mkdir build
cd build
cmake ../example/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
