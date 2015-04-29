//
// Created by Milton Loayza on 4/26/15.
//

#ifndef FOURTRIANGLE_FOURTRIANGLE_H
#define FOURTRIANGLE_FOURTRIANGLE_H

#include "EasyOpenGL.h"

using namespace EasyOpenGL;

class FourTriangle :public GameComponent {
private:
    GLuint vertexBufferObject;
    GLuint vertexArrayObject;
    GLuint shaderProgram;

public:
    FourTriangle();
    ~FourTriangle();
    virtual void initialize();
    virtual void draw();
};


#endif //FOURTRIANGLE_FOURTRIANGLE_H
