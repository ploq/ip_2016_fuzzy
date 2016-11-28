cmake_minimum_required(VERSION 2.8)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    )

file(GLOB SRC *.cpp)
add_executable(app "${SRC}")
#target_link_libraries(app foo)
target_link_libraries(app /usr/lib/x86_64-linux-gnu/libcrypto.a)
