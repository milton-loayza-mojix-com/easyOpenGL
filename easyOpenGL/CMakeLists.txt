cmake_minimum_required(VERSION 3.1)
project(easyOpenGL)

set(PATH_WORKSPACE /Users/milton/test/openGL)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES "src/*.cpp")

include_directories(
        include
        ${PATH_WORKSPACE}/external/gl3w/include
        ${PATH_WORKSPACE}/external/glfw/include
        ${PATH_WORKSPACE}/external/glm
)

add_library(easyOpenGL ${SOURCE_FILES})
