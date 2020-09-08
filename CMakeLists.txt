cmake_minimum_required(VERSION 3.14)
project(engine)

file(GLOB_RECURSE sources src/*.c src/*.h)
list(APPEND sources "main.c")

add_subdirectory(src)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(engine ${sources})

target_link_libraries(engine glfw)
target_link_libraries(engine OpenGL::GL)

