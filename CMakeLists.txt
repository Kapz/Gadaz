cmake_minimum_required(VERSION 3.14)
project(engine)

set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE sources src/*.c src/*.h)
list(APPEND sources "main.c")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(ASSIMP REQUIRED)

include_directories(${ASSIMP_INCLUDE_DIR})

add_executable(engine ${sources})

target_link_libraries(engine glfw)
target_link_libraries(engine GLEW::GLEW)
target_link_libraries(engine OpenGL::GL)
target_link_libraries(engine ${ASSIMP_LIBRARIES})
target_link_libraries(engine m)
