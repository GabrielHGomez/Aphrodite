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
	src/window.cpp
	src/canvas.cpp
	src/texture.cpp
	src/shader.cpp
	src/GLContext.cpp)


target_include_directories(gl_image_viewer PRIVATE
	external)

target_link_libraries(gl_image_viewer PRIVATE
	SDL2::SDL2
	OpenGL::GL
	glad
	${CMAKE_DL_LIBS})

add_custom_command(
  TARGET gl_image_viewer
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
    "$<TARGET_FILE_DIR:gl_image_viewer>/shaders"
    COMMENT "Copying shader directory to build directory..."
)
