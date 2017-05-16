cmake_minimum_required(VERSION 2.8)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    )

file(GLOB SRC *.cpp)
add_executable(app "${SRC}")
set_property(TARGET app PROPERTY CXX_STANDARD 11)
target_link_libraries(app -lcrypto)
