include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/cpp"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/bar/provider/component_if"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/bar/provider/port"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/bar/requirer/component_if"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/bar/requirer/port"
    "${CMAKE_SOURCE_DIR}/namespace_code/global"
    )

file(GLOB SRC *.cpp)
add_executable(app "${SRC}")
target_link_libraries(app foo)
target_link_libraries(app /usr/local/opt/openssl/lib/libcrypto.a)
