#pragma once

// Includes from standard
#include <filesystem>
#include <string>

// Includes from third party libraries


// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases
typedef unsigned int GLuint;
typedef int GLint;

namespace NLUT {
    GLuint createShader(const std::filesystem::path &vertexPath, const std::filesystem::path &fragmentPath);
    GLuint createShader(const std::string &vertexCode, const std::string &fragmentCode);
    GLuint createShader(const char *const vertexCode, const char *const fragmentCode);

    GLint getLoc(const GLuint shaderProgramID, const std::string &name);
    GLint getLoc(const GLuint shaderProgramID, const char *const name);
};