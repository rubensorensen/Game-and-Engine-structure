cmake_minimum_required(VERSION 3.20)

project(game_and_engine VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_LIBRARY_TYPE STATIC)
add_subdirectory(extern/glfw)

file(GLOB_RECURSE ENGINE_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/engine/src/*.cpp)
file(GLOB_RECURSE ENGINE_INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/engine/include/*.cpp)

add_library(engine SHARED
  ${ENGINE_SRC_FILES}
  ${ENGINE_INC_FILES}
)

target_compile_definitions(engine PRIVATE COMPILING_ENGINE)

target_include_directories(engine
  PUBLIC
  ./engine/include/
  ./extern/glfw/include/
)

target_link_libraries(engine
  PRIVATE
  glfw
)

file(GLOB_RECURSE GAME_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/game/src/*.cpp)
file(GLOB_RECURSE GAME_INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/game/include/*.cpp)

add_executable(game
  ${GAME_SRC_FILES}
  ${GAME_INC_FILES}
)

target_include_directories(game
  PUBLIC
  ./game/include/
  ./engine/include/
)

target_link_libraries(game
  PRIVATE
  engine
)
