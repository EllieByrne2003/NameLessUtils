#include "glew.hpp"

// Includes from standard


// Includes from third party libraries
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

// Includes from personal libraries


// Includes from project
#include "../windows/glfw.hpp"

// Forward declarations


// Type aliases

bool initialised = false;

bool NLUT::initialiseGLEW(Logger &logger, GLFWwindow *window) {
    static std::mutex initMutex;
    std::unique_lock initLock(initMutex);

    if(initialised) {
        return true;
    }

    claimContext(window);

    glewExperimental = true;
    if(glewInit() != GLEW_OK) {
        logger.addError("Failed to initialise GLEW.");
    } else {
        initialised = true;
    }

    return initialised;
}

bool NLUT::GLEWInitialized() {
    return initialised;
}