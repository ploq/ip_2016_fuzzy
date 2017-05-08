cmake_minimum_required(VERSION 2.8)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
#    "/usr/local/opt/openssl/include"
    )

file(GLOB SRC *.cpp)
add_executable(app "${SRC}")
#target_link_libraries(app foo)
set_property(TARGET app PROPERTY CXX_STANDARD 11)
#target_link_libraries(app /usr/local/opt/openssl/lib/libcrypto.a)
target_link_libraries(app -lcrypto)
