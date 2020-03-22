//
// Created by Milton Loayza on 5/10/15.
//

#include "Chapter02.h"

using namespace EasyOpenGL;

Chapter02::Chapter02() {

}

Chapter02::~Chapter02() {
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteProgram(shaderProgram);
}

void Chapter02::initialize() {
    // Compile shaders
    std::string path = "/Users/milton/test/openGL/book-chapter-02/";
    ShaderBuilder* shaderBuilder = new ShaderBuilder();
    shaderBuilder->addFromFile(GL_VERTEX_SHADER, path + "shaders/chapter02.vert");
    shaderBuilder->addFromFile(GL_FRAGMENT_SHADER, path + "shaders/chapter02.frag");
    shaderProgram = glCreateProgram();
    shaderBuilder->build(shaderProgram);

    // Create vertex array object
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);
}

void Chapter02::draw() {
//    double currentTime = glfwGetTime();
//    const GLfloat color[] = { (float)sin(currentTime) * 0.5f + 0.5f, (float)cos(currentTime) * 0.5f + 0.5f,
//                              0.0f, 1.0f };
//    glClearBufferfv(GL_COLOR, 0, color);

    const GLfloat color[] = { 0.0f, 0.2f, 0.0f, 1.0f };
    glClearBufferfv(GL_COLOR, 0, color);

    // Use the program object we created earlier for rendering
    glUseProgram(shaderProgram);

    // Draw one point
//    glPointSize(40.0f);
//    glDrawArrays(GL_POINTS, 0, 1);

    // Draw one triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

}


