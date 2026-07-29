#pragma once

// Includes from standard


// Includes from third party libraries


// Includes from personal libraries


// Includes from project
#include "../logger/logger.hpp"

// Forward declarations
struct GLFWwindow;

// Type aliases

namespace NLUT {
    bool initialiseGLEW(Logger &logger, GLFWwindow *window);
    bool GLEWInitialised();
};