cmake_minimum_required(VERSION 3.1)
project(easyOpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES "src/*.cpp")

include_directories(include)

include_directories(/Users/mloayza/projects/openGL/easyOpenGL-workspace/external/gl3w/include)
include_directories(/Users/mloayza/projects/openGL/easyOpenGL-workspace/external/glfw/include)
include_directories(/Users/mloayza/projects/openGL/easyOpenGL-workspace/external/glm)

add_library(easyOpenGL ${SOURCE_FILES})
