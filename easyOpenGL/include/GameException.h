//
// Created by Milton Loayza on 4/25/15.
//

#ifndef EASYOPENGL_GAMEEXCEPTION_H
#define EASYOPENGL_GAMEEXCEPTION_H


#include "EasyOpenGL.h"

namespace EasyOpenGL {
    class GameException : public std::exception
    {
    private:
        const char*  errorMsg;
    public:
        GameException(const char* message);
        const char* const whatw() const;
    };
}

#endif //EASYOPENGL_GAMEEXCEPTION_H
