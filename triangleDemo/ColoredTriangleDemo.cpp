//
// Created by Milton Loayza on 4/26/15.
//

#include "ColoredTriangleDemo.h"

using namespace EasyOpenGL;

ColoredTriangleDemo::ColoredTriangleDemo()
        : shaderProgram(), vertexArrayObject(0), vertexBuffer(0)
{
}

ColoredTriangleDemo::~ColoredTriangleDemo()
{
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteBuffers(1, &vertexBuffer);
}

void ColoredTriangleDemo::initialize() {
    std::string path = "/Users/milton/test/openGL/triangleDemo/";
    ShaderBuilder* shaderBuilder = new ShaderBuilder();
    shaderBuilder->addFromFile(GL_VERTEX_SHADER, path + "shaders/ColoredTriangleDemo.vert");
    shaderBuilder->addFromFile(GL_FRAGMENT_SHADER, path + "shaders/ColoredTriangleDemo.frag");
    shaderProgram = glCreateProgram();
    shaderBuilder->build(shaderProgram);

    // Create the vertex buffer
    VertexPositionColor vertices[] =
            {
                    VertexPositionColor(glm::vec4(0.75f, -0.25f, 0.0f, 1.0f), ColorHelper::Red),
                    VertexPositionColor(glm::vec4(0.0f, 0.5f, 0.0f, 1.0f), ColorHelper::Green),
                    VertexPositionColor(glm::vec4(-0.75f, -0.25f, 0.0f, 1.0f), ColorHelper::Blue)
            };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create vertex array object
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    glVertexAttribPointer(VertexAttributePosition, 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), (void*)offsetof(VertexPositionColor, Position));
    glEnableVertexAttribArray(VertexAttributePosition);

    glVertexAttribPointer(VertexAttributeColor, 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), (void*)offsetof(VertexPositionColor, Color));
    glEnableVertexAttribArray(VertexAttributeColor);

    glBindVertexArray(0);
}


void ColoredTriangleDemo::draw() {
    glBindVertexArray(vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glUseProgram(shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
