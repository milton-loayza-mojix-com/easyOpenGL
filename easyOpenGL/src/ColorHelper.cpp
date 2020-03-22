//
// Created by Milton Loayza on 4/26/15.
//

#include "ColorHelper.h"

namespace EasyOpenGL
{
    std::random_device ColorHelper::device;
    std::default_random_engine ColorHelper::generator(device());
    std::uniform_real_distribution<float> ColorHelper::distribution(0, 1);

    const glm::vec4 ColorHelper::Black =			glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    const glm::vec4 ColorHelper::White =			glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    const glm::vec4 ColorHelper::Red =				glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    const glm::vec4 ColorHelper::Green =			glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
    const glm::vec4 ColorHelper::Blue =				glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
    const glm::vec4 ColorHelper::Yellow =			glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
    const glm::vec4 ColorHelper::BlueGreen =		glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
    const glm::vec4 ColorHelper::Purple =			glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
    const glm::vec4 ColorHelper::CornflowerBlue =	glm::vec4(0.392f, 0.584f, 0.929f, 1.0f);
    const glm::vec4 ColorHelper::Wheat =			glm::vec4(0.961f, 0.871f, 0.702f, 1.0f);
    const glm::vec4 ColorHelper::LightGray =		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);

    glm::vec4 ColorHelper::randomColor()
    {
        float r = distribution(generator);
        float g = distribution(generator);
        float b = distribution(generator);

        return glm::vec4(r, g, b, 1.0f);
    }
}


