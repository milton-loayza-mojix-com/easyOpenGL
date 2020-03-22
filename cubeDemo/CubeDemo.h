//
// Created by Milton Loayza on 4/26/15.
//

#ifndef EASYOPENGL_CUBEDEMO_H
#define EASYOPENGL_CUBEDEMO_H

#include "EasyOpenGL.h"
using namespace EasyOpenGL;

class CubeDemo : public GameComponent
{

public:
    CubeDemo();
    ~CubeDemo();

    virtual void initialize();
    virtual void update();
    virtual void draw();

private:
    enum VertexAttribute
    {
        VertexAttributePosition = 0,
        VertexAttributeColor = 1
    };

    static const GLfloat rotationRate;

    GLuint shaderProgram;
    GLuint vertexArrayObject;
    GLuint vertexBuffer;
    GLuint indexBuffer;
    GLint worldViewProjectionLocation;
    glm::mat4 worldMatrix;
};

#endif //EASYOPENGL_CUBEDEMO_H
