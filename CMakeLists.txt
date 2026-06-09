cmake_minimum_required(VERSION 3.22.1)
project(gl_image_viewer LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(glad STATIC external/src/glad.c)
target_include_directories(glad PUBLIC external/include)

add_executable(gl_image_viewer 
	src/main.cpp
	src/window.cpp)

target_include_directories(gl_image_viewer PRIVATE
	external)

target_link_libraries(gl_image_viewer PRIVATE
	SDL2::SDL2
	OpenGL::GL
	glad
	${CMAKE_DL_LIBS})

