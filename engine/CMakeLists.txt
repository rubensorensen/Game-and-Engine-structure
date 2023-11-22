cmake_minimum_required(VERSION 3.20)

project(engine_proj VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(GLFW_LIBRARY_TYPE STATIC)
add_subdirectory(extern/glfw)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_library(engine SHARED
  ${SRC_FILES}
  ${INC_FILES}
)

target_compile_definitions(engine PRIVATE COMPILING_ENGINE)

target_include_directories(engine
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/extern/glfw/include/
)

target_link_libraries(engine
  PRIVATE
  glfw
)
