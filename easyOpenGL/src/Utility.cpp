//
// Created by Milton Loayza on 4/25/15.
//

#include "EasyOpenGL.h"

namespace EasyOpenGL
{
    void Utility::loadBinaryFile(const std::string &filename, std::vector<char> &data)
    {
        std::ifstream file(filename.c_str(), std::ios::binary);
        if (not file.is_open())
        {
            throw GameException(Utility::concatString("Could not open file ", filename));
        }

        file.seekg(0, std::ios::end);
        unsigned int size = (unsigned)file.tellg();

        if (size > 0)
        {
            data.resize(size);
            file.seekg(0, std::ios::beg);
            file.read(&data.front(), size);
        }

        file.close();

    }

    const char* Utility::concatString(const char * s1, const std::string &s2)
    {
        char * s3 = (char *) malloc(1 + strlen(s1)+ strlen(s2.c_str()));
        strcpy(s3, s1);
        strcat(s3, s2.c_str());
        return s3;
    }
}
