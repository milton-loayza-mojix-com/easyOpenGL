//
// Created by Milton Loayza on 4/25/15.
//

#ifndef EASYOPENGL_EASYOPENGL_H
#define EASYOPENGL_EASYOPENGL_H

#include <stdio.h>
#include <iosfwd>
#include <vector>
#include <string>
#include <exception>
#include <functional>
#include <map>
#include <sstream>
#include <fstream>
#include <random>

typedef std::function<void(int, int, int, int)> KeyboardHandler;

#include <GL/gl3w.h>
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtx/simd_mat4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/trigonometric.hpp"

#include "GameComponent.h"
#include "GameException.h"
#include "Game.h"
#include "ShaderBuilder.h"
#include "Utility.h"
#include "ColorHelper.h"
#include "VertexDeclarations.h"



#endif //EASYOPENGL_EASYOPENGL_H
