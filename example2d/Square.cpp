//
// Created by Milton Loayza on 4/27/15.
//

#include "square.h"

Square::Square()
:vertexBufferObject(0), vertexArrayObject(0), shaderProgram(0)
{
}

Square::~Square() {
    glDeleteBuffers(1, &vertexBufferObject);
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteProgram(shaderProgram);
}

void Square::initialize() {

    //******  LOAD AND COMPILE SHADERs  ********/
    std::string path = "/Users/mloayza/projects/openGL/easyOpenGL-workspace/example2d/";
    shaderProgram = glCreateProgram();
    ShaderBuilder* shaderBuilder = new ShaderBuilder();
    shaderBuilder->addFromFile(GL_VERTEX_SHADER, path + "shaders/square.vert");
    shaderBuilder->addFromFile(GL_FRAGMENT_SHADER, path + "shaders/square.frag");
    shaderBuilder->build(shaderProgram);

    //******  PROCESS VERTEX BUFFER OBJECT  ********/
    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

    //******  PROCESS VERTEX ARRAY OBJECT  ********/
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);


    // define vertex positions and colors
    GLfloat vertexPositions[8] = {
            -0.5, -0.5,
            0.5, -0.5,
            0.5, 0.5,
            -0.5, 0.5,
    };

    GLuint indices[6] = {
            0, 1, 2,
            2, 3, 0
    };

//    GLfloat vertexPositions[12] = {
//            0.0, 0.0,
//            0.5, 0.0,
//            0.5, 0.5,
//
//            0.0, 0.0,
//            0.5, 0.5,
//            0.0, 0.5,
//    };

    GLfloat colors[12] = {
            0.1, 0.4, 0.7,
            0.4, 0.7, 0.1,
            0.7, 0.1, 0.4,
            0.1, 0.2, 0.3
    };

    // define the total for buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions) + sizeof(colors), NULL, GL_STATIC_DRAW);

    // Transfer the vertex positions:
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertexPositions), vertexPositions);

    // Transfer the vertex colors:
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(colors), colors);

    // Create an Element Array Buffer that will store the indices array:
    GLuint eab;
    glGenBuffers(1, &eab);

    // Transfer the data from indices to eab
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eab);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Position attribute
    GLint position_attribute = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(position_attribute, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(position_attribute);

    // Color attribute
    GLint color_attribute = glGetAttribLocation(shaderProgram, "color");
    glVertexAttribPointer(color_attribute, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *)sizeof(vertexPositions));
    glEnableVertexAttribArray(color_attribute);

    glUseProgram(shaderProgram);
}

void Square::draw() {
    glBindVertexArray(vertexArrayObject);
//    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}
