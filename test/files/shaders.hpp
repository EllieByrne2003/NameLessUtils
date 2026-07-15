#pragma once

// Includes from standard
#include <string>

// Includes from third party libraries


// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases
typedef unsigned int GLuint;
typedef int GLint;

namespace NLUT {
    GLuint createShader(const std::string &vertexPath, const std::string &fragmentPath);

    GLint getLoc(const GLuint shaderProgramID, const std::string &name);
    GLint getLoc(const GLuint shaderProgramID, const char *const name);
};