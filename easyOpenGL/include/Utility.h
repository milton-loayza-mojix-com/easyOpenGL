//
// Created by Milton Loayza on 4/25/15.
//

#ifndef EASYOPENGL_UTILITY_H
#define EASYOPENGL_UTILITY_H

#include "EasyOpenGL.h"

namespace EasyOpenGL
{
    class Utility {
    public:
        static void loadBinaryFile(const std::string &filename, std::vector<char> &data);
        static const char* concatString(const char * s1, const std::string &s2);

    };
}

#endif //EASYOPENGL_UTILITY_H
