file(GLOB SRC bar/provider/*.cpp bar/requirer/*.cpp)
add_library(foo "${SRC}")
