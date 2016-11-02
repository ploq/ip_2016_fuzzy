include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/cpp"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/bar/provider/component_if"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/bar/provider/port"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/bar/requirer/component_if"
    "${CMAKE_SOURCE_DIR}/namespace_code/foo/bar/requirer/port"
    "${CMAKE_SOURCE_DIR}/namespace_code/global"
    )


file(GLOB SRC PortHandler.hpp bar/provider/*.cpp bar/requirer/*.cpp)
add_library(foo "${SRC}")
