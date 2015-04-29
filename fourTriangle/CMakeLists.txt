cmake_minimum_required(VERSION 3.1)
project(fourTriangle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(PATH_WORKSPACE /Users/mloayza/projects/openGL/easyOpenGL-workspace)
set(SOURCE_FILES main.cpp FourTriangle.cpp FourTriangle.h)

include_directories (
    ${PATH_WORKSPACE}/external/gl3w/include
    ${PATH_WORKSPACE}/external/glm
    ${PATH_WORKSPACE}/easyOpenGL/include
)

link_directories (
    ${PATH_WORKSPACE}/external/gl3w/lib
    ${PATH_WORKSPACE}/external/glfw/lib
    /System/Library/Frameworks/CoreFoundation.framework
    ${PATH_WORKSPACE}/easyOpenGL/Debug
)

add_executable(fourTriangle ${SOURCE_FILES})
target_link_libraries (fourTriangle glfw gl3w CoreFoundation easyOpenGL)

