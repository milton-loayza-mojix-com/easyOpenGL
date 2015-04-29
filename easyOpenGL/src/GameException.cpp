//
// Created by Milton Loayza on 4/25/15.
//

#include "GameException.h"

namespace EasyOpenGL
{
    GameException::GameException(const char* errorMsg):
            errorMsg(errorMsg)
    {
    }

    const char* const GameException::whatw() const
    {
        return errorMsg;
    }
}