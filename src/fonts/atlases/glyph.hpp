#pragma once

// Includes from standard


// Includes from third party libraries
#include <glm/glm.hpp>

// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases
typedef unsigned int GLuint;

namespace NLUT {
    namespace Fonts {
        struct Glyph {
            float advance = 0.0f;

            glm::vec2 pos0 = glm::vec2(0.0f); // Bottom left position
            glm::vec2 pos1 = glm::vec2(0.0f); // Top right position

            glm::vec2 uv0  = glm::vec2(0.0f); // Bottom left atlas co-oridinate
            glm::vec2 uv1  = glm::vec2(0.0f); // Top right atlas co-ordinate

            bool isWhitespace = false;
        };
    }
}