//
// Created by Milton Loayza on 4/26/15.
//

#include "CubeDemo.h"
using namespace glm;

const GLfloat CubeDemo::rotationRate = 180.0f;

CubeDemo::CubeDemo()
        : GameComponent(), shaderProgram(), vertexArrayObject(0), vertexBuffer(0),
          indexBuffer(0), worldViewProjectionLocation(-1), worldMatrix()
{
}

CubeDemo::~CubeDemo()
{
    glDeleteBuffers(1, &indexBuffer);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteProgram(shaderProgram);
}

void CubeDemo::initialize()
{
    std::string path = "/Users/milton/test/openGL/cubeDemo/";
    ShaderBuilder* shaderBuilder = new ShaderBuilder();
    shaderBuilder->addFromFile(GL_VERTEX_SHADER, path + "shaders/CubeDemo.vert");
    shaderBuilder->addFromFile(GL_FRAGMENT_SHADER, path + "shaders/CubeDemo.frag");
    shaderProgram = glCreateProgram();
    shaderBuilder->build(shaderProgram);

    // Create the vertex buffer object
    VertexPositionColor vertices[] =
            {
                    VertexPositionColor(vec4(-1.0f, +1.0f, -1.0f, 1.0f), ColorHelper::Green),
                    VertexPositionColor(vec4(+1.0f, +1.0f, -1.0f, 1.0f), ColorHelper::Yellow),
                    VertexPositionColor(vec4(+1.0f, +1.0f, +1.0f, 1.0f), ColorHelper::White),
                    VertexPositionColor(vec4(-1.0f, +1.0f, +1.0f, 1.0f), ColorHelper::BlueGreen),

                    VertexPositionColor(vec4(-1.0f, -1.0f, +1.0f, 1.0f), ColorHelper::Blue),
                    VertexPositionColor(vec4(+1.0f, -1.0f, +1.0f, 1.0f), ColorHelper::Purple),
                    VertexPositionColor(vec4(+1.0f, -1.0f, -1.0f, 1.0f), ColorHelper::Red),
                    VertexPositionColor(vec4(-1.0f, -1.0f, -1.0f, 1.0f), ColorHelper::Black)
            };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint indices[] =
            {
                    0, 2, 1,
                    0, 3, 2,

                    4, 6, 5,
                    4, 7, 6,

                    3, 5, 2,
                    3, 4, 5,

                    2, 6, 1,
                    2, 5, 6,

                    1, 6, 7,
                    1, 7, 0,

                    0, 4, 3,
                    0, 7, 4
            };

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Create the vertex array object
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    glVertexAttribPointer(VertexAttributePosition, 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), (void*)offsetof(VertexPositionColor, Position));
    glEnableVertexAttribArray(VertexAttributePosition);

    glVertexAttribPointer(VertexAttributeColor, 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), (void*)offsetof(VertexPositionColor, Color));
    glEnableVertexAttribArray(VertexAttributeColor);

    glBindVertexArray(0);

    worldViewProjectionLocation = glGetUniformLocation(shaderProgram, "WorldViewProjection");
    if (worldViewProjectionLocation == -1)
    {
        throw GameException("glGetUniformLocation() did not find uniform location.");
    }
}

void CubeDemo::update()
{
//    static float angle = 0.0f;
//
//    angle += static_cast<float>(gameTime.ElapsedGameTime()) * rotationRate;
//
//    worldMatrix = glm::rotate(glm::mat4(), angle, Vector3Helper::Up);
}

void CubeDemo::draw()
{
    glBindVertexArray(vertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

    glUseProgram(shaderProgram);

//    mat4 wvp = mCamera->ViewProjectionMatrix() * worldMatrix;
//    glUniformMatrix4fv(worldViewProjectionLocation, 1, GL_FALSE, &wvp[0][0]);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
