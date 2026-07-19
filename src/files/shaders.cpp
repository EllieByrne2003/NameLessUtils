#include "shaders.hpp"

// Includes from standard
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Includes from third party libraries
#include <GL/glew.h>
#include <GL/gl.h>

// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases
typedef unsigned int GLuint;
typedef int GLint;

GLuint NLUT::createShader(const std::filesystem::path &vertexPath, const std::filesystem::path &fragmentPath) {
    // Load files into strings
    std::string vertexCode;
    std::ifstream vertexFile(vertexPath);
    if(vertexFile.is_open()) {
        std::stringstream sstr;
        sstr << vertexFile.rdbuf();
        vertexCode = sstr.str();
        vertexFile.close();
    } else {
        std::cerr << "Couldn't load: " << vertexPath << std::endl;
        return 0;
    }

    std::string fragmentCode;
    std::ifstream fragmentFile(fragmentPath);
    if(fragmentFile.is_open()) {
        std::stringstream sstr;
        sstr << fragmentFile.rdbuf();
        fragmentCode = sstr.str();
        fragmentFile.close();
    } else {
        std::cerr << "Couldn't load: " << fragmentPath << std::endl;
        return 0;
    }

    return createShader(vertexCode.c_str(), fragmentCode.c_str());
}

GLuint NLUT::createShader(const std::string &vertexCode, const std::string &fragmentCode) {
    return createShader(vertexCode.c_str(), fragmentCode.c_str());
}

GLuint NLUT::createShader(const char *const vertexCode, const char *const fragmentCode) {

    // Error checking info
    int ok = 0;
    int infoLogLength;

    // Compile vertex shader
    unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vertexCode, NULL);
    glCompileShader(vertexShaderID);

    // Check vertex compilation
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &ok);
    glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(!ok) {
        if(infoLogLength > 0) {
            std::vector<char> log(infoLogLength + 1);
            glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &log[0]);
            std::cerr << &log[0] << std::endl;
        }

        glDeleteShader(vertexShaderID);

        return 0;
    }

    // Compile fragment shader
    unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderID, 1, &fragmentCode, NULL);
    glCompileShader(fragmentShaderID);

    // Check fragment compilation
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &ok);
    glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if(!ok) {
        if(infoLogLength > 0) {
            std::vector<char> log(infoLogLength + 1);
            glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &log[0]);
            std::cerr << &log[0] << std::endl;
        }

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);

        return 0;
    }

    // Link program
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);
        
    // Check program linking
    glGetProgramiv(programID, GL_LINK_STATUS, &ok);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

    if(!ok) {
        if(infoLogLength > 0) {
            std::vector<char> log(infoLogLength + 1);
            glGetProgramInfoLog(programID, infoLogLength, NULL, &log[0]);
            std::cerr << &log[0] << std::endl;
        }
        
        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
        glDeleteProgram(programID);

        return 0;
    }

    // Cleanup vertex and fragment
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    return programID;
}

GLint NLUT::getLoc(const GLuint shaderProgramID, const std::string &name) {
    return getLoc(shaderProgramID, name.c_str());
}

GLint NLUT::getLoc(const GLuint shaderProgramID, const char *const name) {
    return glGetUniformLocation(shaderProgramID, name);
}