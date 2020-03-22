//
// Created by Milton Loayza on 4/26/15.
//

#ifndef EASYOPENGL_COLORHELPER_H
#define EASYOPENGL_COLORHELPER_H


#include "EasyOpenGL.h"

namespace EasyOpenGL
{
    class ColorHelper {
    public:
        static const glm::vec4 Black;
        static const glm::vec4 White;
        static const glm::vec4 Red;
        static const glm::vec4 Green;
        static const glm::vec4 Blue;
        static const glm::vec4 Yellow;
        static const glm::vec4 BlueGreen;
        static const glm::vec4 Purple;
        static const glm::vec4 CornflowerBlue;
        static const glm::vec4 Wheat;
        static const glm::vec4 LightGray;

        static glm::vec4 randomColor();

    private:
        static std::random_device device;
        static std::default_random_engine generator;
        static std::uniform_real_distribution<float> distribution;

        ColorHelper();
    };

}



#endif //EASYOPENGL_COLORHELPER_H
