cmake_minimum_required(VERSION 3.20)

project(test_project_proj VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE INC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_executable(test_project
  ${SRC_FILES}
  ${INC_FILES}
)

target_include_directories(test_project PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_link_libraries(test_project PRIVATE
  engine
)
