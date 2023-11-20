cmake_minimum_required(VERSION 3.20)

project(game_and_engine VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# file(GLOB_RECURSE ENGINE_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/engine/src/*.cpp)
# file(GLOB_RECURSE ENGINE_INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/engine/include/*.cpp)

add_library(engine SHARED
  # ENGINE_SRC_FILES
  # ENGINE_INC_FILES
  ./engine/src/core.cpp
)

target_include_directories(engine
  PUBLIC
  ./engine/include/
)

# target_compile_definitions(engine PRIVATE __declspec(dllexport) FOO=1 BAR=1)

# file(GLOB_RECURSE GAME_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/game/src/*.cpp)
# file(GLOB_RECURSE GAME_INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/game/include/*.cpp)

add_executable(game
  # GAME_SRC_FILES
  # GAME_INC_FILES
  ./game/src/main.cpp
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