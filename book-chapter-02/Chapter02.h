//
// Created by Milton Loayza on 5/10/15.
//

#ifndef BOOK_CHAPTER_02_CHAPTER02_H
#define BOOK_CHAPTER_02_CHAPTER02_H

#include "EasyOpenGL.h"

using namespace EasyOpenGL;


class Chapter02 : public GameComponent {
public:
    Chapter02();
    ~Chapter02();
    virtual void initialize();
    virtual void draw();
private:
    GLuint shaderProgram;
    GLuint vertexArrayObject;
    GLuint vertexBuffer;
};


#endif //BOOK_CHAPTER_02_CHAPTER02_H
