//
// Created by Milton Loayza on 4/25/15.
//


#include "EasyOpenGL.h"

namespace EasyOpenGL {

    void ShaderBuilder::addFromFile(GLenum shaderType, std::string fileName) {
        shaders.push_back(ShaderDefinition(shaderType, fileName));
    }

    GLuint ShaderBuilder::compileShaderFromFile(GLenum shaderType, const std::string &filename)
    {
        std::vector<char> shaderSource;
        Utility::loadBinaryFile(filename, shaderSource);
        const GLchar* sourcePointer = &shaderSource[0];
        GLint  length = shaderSource.size();

        GLuint shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &sourcePointer, &length);
        glCompileShader(shader);

        GLint compileStatus;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
        if (compileStatus != GL_TRUE)
        {
            GLint logLength;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
            std::string log;
            log.reserve(logLength);
            glGetShaderInfoLog(shader, logLength, nullptr, const_cast<GLchar*>(log.c_str()));
            std::stringstream errorMessage;
            errorMessage << "glCompileShader() failed " <<  filename.c_str() << "\n"<< log.c_str();
            throw GameException(Utility::concatString("", errorMessage.str()));
        }

        return shader;
    }
    void ShaderBuilder::build(GLuint &mProgram) {
        std::vector<GLuint> compiledShaders;
        compiledShaders.reserve(shaders.size());

        for (ShaderDefinition shaderDefiniton : shaders)
        {
            GLuint compiledShader = compileShaderFromFile(shaderDefiniton.first, shaderDefiniton.second);
            glAttachShader(mProgram, compiledShader);
            compiledShaders.push_back(compiledShader);
        }

        glLinkProgram(mProgram);
        GLint linkStatus;
        glGetProgramiv(mProgram, GL_LINK_STATUS, &linkStatus);
        if (linkStatus != GL_TRUE)
        {
            GLint logLength;
            glGetProgramiv(mProgram, GL_INFO_LOG_LENGTH, &logLength);

            std::string log;
            log.reserve(logLength);

            glGetProgramInfoLog(mProgram, logLength, nullptr, const_cast<GLchar*>(log.c_str()));

            std::stringstream errorMessage;
            errorMessage << "glLinkProgram() failed.\n" << log.c_str();
            throw GameException(Utility::concatString("", errorMessage.str()));
        }

        for (GLuint compiledShader : compiledShaders)
        {
            glDeleteShader(compiledShader);
        }
    }
}

