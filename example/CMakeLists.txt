cmake_minimum_required(VERSION 2.8)

add_compile_options(-std=c++11)
include_directories("/usr/local/opt/openssl/include")
### Project settings
project(example)

add_subdirectory(namespace_code)
add_subdirectory(app_code)
