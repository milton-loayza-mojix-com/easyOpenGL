//
// Created by Milton Loayza on 4/25/15.
//

#ifndef EASYOPENGL_POINTDEMO_H
#define EASYOPENGL_POINTDEMO_H

#include "EasyOpenGL.h"

using namespace EasyOpenGL;

class PointDemo : public GameComponent
{
private:
    GLuint shaderProgram;
    GLuint vertexArrayObject;
public:
    PointDemo();
    ~PointDemo();
    virtual void initialize();
    virtual void draw();
};

#endif //EASYOPENGL_POINTDEMO_H
