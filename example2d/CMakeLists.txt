cmake_minimum_required(VERSION 3.1)
project(example2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(PATH_WORKSPACE /Users/milton/test/openGL)
set(SOURCE_FILES main.cpp Square.cpp Square.h)

include_directories (
        ${PATH_WORKSPACE}/external/gl3w/include
        ${PATH_WORKSPACE}/external/glfw/include
        ${PATH_WORKSPACE}/external/glm
        ${PATH_WORKSPACE}/easyOpenGL/include
)

link_directories (
    ${PATH_WORKSPACE}/external/gl3w/lib
    ${PATH_WORKSPACE}/external/glfw/lib
    /System/Library/Frameworks/CoreFoundation.framework
    ${PATH_WORKSPACE}/easyOpenGL/Debug
)

add_executable(example2d ${SOURCE_FILES})
target_link_libraries (example2d glfw.3 gl3w "-framework CoreFoundation" easyOpenGL)


