//
// Created by Milton Loayza on 4/25/15.
//

#ifndef EASYOPENGL_SHADERBUILDER_H
#define EASYOPENGL_SHADERBUILDER_H

#include "EasyOpenGL.h"

namespace EasyOpenGL
{
    typedef std::pair<GLenum, std::string> ShaderDefinition;
    class ShaderBuilder {

    private:
        std::vector<ShaderDefinition> shaders;
        GLuint compileShaderFromFile(GLenum shaderType, const std::string &filename);

    public:
        void addFromFile(GLenum shaderType, std::string fileName);
        void build(GLuint& mProgram);

    };
}

#endif //EASYOPENGL_SHADERBUILDER_H
