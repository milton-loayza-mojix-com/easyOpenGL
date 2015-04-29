//
// Created by Milton Loayza on 4/27/15.
//

#ifndef EXAMPLE2D_SQUARE_H
#define EXAMPLE2D_SQUARE_H

#include "EasyOpenGL.h"
using namespace EasyOpenGL;

class Square : public GameComponent {
private:
    GLuint vertexBufferObject;
    GLuint vertexArrayObject;
    GLuint shaderProgram;
public:
    Square();
    ~Square();
    virtual void initialize();
    virtual void draw();

};


#endif //EXAMPLE2D_SQUARE_H
