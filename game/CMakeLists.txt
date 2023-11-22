cmake_minimum_required(VERSION 3.20)

project(game_proj VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_executable(game
  ${SRC_FILES}
  ${INC_FILES}
)

target_include_directories(game
  PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/../engine/include/
)

target_link_libraries(game
  PRIVATE
  engine
)
