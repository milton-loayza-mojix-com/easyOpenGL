cmake_minimum_required(VERSION 3.2)
project(book_chapter_02)

set(PATH_WORKSPACE /Users/milton/test/openGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp )

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

add_executable(book_chapter_02 ${SOURCE_FILES} Chapter02.cpp Chapter02.h)

target_link_libraries (book_chapter_02 glfw.3 gl3w "-framework CoreFoundation" easyOpenGL)