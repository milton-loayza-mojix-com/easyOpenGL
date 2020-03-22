//
// Created by Milton Loayza on 4/25/15.
//


#include "PointDemo.h"

using namespace EasyOpenGL;

PointDemo::PointDemo()
        : shaderProgram(0), vertexArrayObject(0)
{
}

PointDemo::~PointDemo()
{
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &vertexArrayObject);
}

void PointDemo::initialize() {
    std::string path = "/Users/milton/test/openGL/pointDemo/";
    ShaderBuilder* shaderBuilder = new ShaderBuilder();
    shaderBuilder->addFromFile(GL_VERTEX_SHADER, path + "shaders/PointDemo.vert");
    shaderBuilder->addFromFile(GL_FRAGMENT_SHADER, path + "shaders/PointDemo.frag");
    shaderProgram = glCreateProgram();
    shaderBuilder->build(shaderProgram);

    // Create vertex array object
    glGenVertexArrays(1, &vertexArrayObject);
}


void PointDemo::draw() {
    glBindVertexArray(vertexArrayObject);
    glUseProgram(shaderProgram);
    glPointSize(80.0f);
    glDrawArrays(GL_POINTS, 0, 1);
    glBindVertexArray(0);
}

