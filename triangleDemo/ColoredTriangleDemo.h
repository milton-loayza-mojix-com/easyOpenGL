//
// Created by Milton Loayza on 4/26/15.
//

#ifndef EASYOPENGL_COLOREDTRIANGLEDEMO_H
#define EASYOPENGL_COLOREDTRIANGLEDEMO_H

#include "EasyOpenGL.h"

using namespace EasyOpenGL;

class ColoredTriangleDemo : public GameComponent
{
private:
    enum VertexAttribute
    {
        VertexAttributePosition = 0,
        VertexAttributeColor = 1
    };
    GLuint shaderProgram;
    GLuint vertexArrayObject;
    GLuint vertexBuffer;
public:
    ColoredTriangleDemo();
    ~ColoredTriangleDemo();
    virtual void initialize();
    virtual void draw();
};

#endif //EASYOPENGL_COLOREDTRIANGLEDEMO_H
