//
// Created by Milton Loayza on 4/26/15.
//

#include "FourTriangle.h"

using namespace EasyOpenGL;


FourTriangle::FourTriangle()
        :vertexBufferObject(0), vertexArrayObject(0), shaderProgram(0)
{
}

FourTriangle::~FourTriangle() {
    glDeleteBuffers(1, &vertexBufferObject);
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteProgram(shaderProgram);
}

void FourTriangle::initialize() {
    GLfloat vertices_position[24] = {
            0.0, 0.0,
            0.5, 0.0,
            0.5, 0.5,

            0.0, 0.0,
            0.0, 0.5,
            -0.5f, 0.5,

            0.0, 0.0,
            -0.5, 0.0,
            -0.5, -0.5,

            0.0, 0.0,
            0.0, -0.5,
            0.5, -0.5,
    };

    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_position), vertices_position, GL_STATIC_DRAW);


    GLfloat colors[36];

    // Initialize the random seed from the system time
    srand(time(NULL));

    // Fill colors with random numbers from 0 to 1, use continuous polynomials for r,g,b:
    int k = 0;
    for(int i = 0; i < sizeof(colors)/sizeof(float)/3; ++i) {
        		float t = (float)rand()/(float)RAND_MAX;
        		colors[k] = 9*(1-t)*t*t*t;
            	k++;
        		colors[k] = 15*(1-t)*(1-t)*t*t;
         		k++;
         		colors[k] = 8.5*(1-t)*(1-t)*(1-t)*t;
         		k++;

         	}


    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_position) + sizeof(colors), NULL, GL_STATIC_DRAW);

    // Transfer the vertex positions:
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices_position), vertices_position);

    // Transfer the vertex colors:
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices_position), sizeof(colors), colors);

    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);


    std::string path = "/Users/milton/test/openGL/fourTriangle/";
    shaderProgram = glCreateProgram();
    ShaderBuilder* shaderBuilder = new ShaderBuilder();

    shaderBuilder->addFromFile(GL_VERTEX_SHADER, path + "shaders/fourTriangle.vert");
    shaderBuilder->addFromFile(GL_FRAGMENT_SHADER, path + "shaders/fourTriangle.frag");
    shaderBuilder->build(shaderProgram);

    GLint position_attribute = glGetAttribLocation(shaderProgram, "position");
    glVertexAttribPointer(position_attribute, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(position_attribute);

    // Color attribute
    GLint color_attribute = glGetAttribLocation(shaderProgram, "color");
    glVertexAttribPointer(color_attribute, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid *)sizeof(vertices_position));
    glEnableVertexAttribArray(color_attribute);



    glUseProgram(shaderProgram);

}
void FourTriangle::draw() {
    glBindVertexArray(vertexArrayObject);
    glDrawArrays(GL_TRIANGLES, 0, 12);

//    glPointSize(80.0f);
//    glDrawArrays(GL_POINTS, 0, 12);
}

