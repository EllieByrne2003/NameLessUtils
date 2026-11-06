#pragma once

// Includes from standard
#include <vector>
#include <string>

// Includes from third party libraries
#define GLM_FORCE_EXPLICIT_CTOR
#include <glm/glm.hpp>
using namespace glm;

// Includes from personal libraries


// Includes from projectl libraries


// Includes from project


// Forward declarations


// Type aliases
typedef unsigned int GLuint;

namespace NLUT {
    struct Vertex {
        vec3 position;
        vec3 normal;
        vec2 uv;

        vec3 tangent;

        Vertex(const vec3 &position, const vec3 &normal, const vec2 &uv, const vec3 &tangent = vec3(0.0f)) {
            this->position = position;
            this->normal = normal;
            this->uv = uv;

            this->tangent = tangent;
        }
    };

    int readOBJ(const std::string &filepath, GLuint &VAO, GLuint &VBO, GLuint &EBO, std::vector<Vertex> &vertices);
    int readOBJ(const std::string &filepath, GLuint &VAO, GLuint &VBO, GLuint &EBO);
};