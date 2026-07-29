#include "glfw.hpp"

// Includes from standard
#include <mutex>

// Includes from third party libraries
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases


static std::mutex contextMutex;

static bool initialised = false;

bool NLUT::intialiseGLFW(Logger &logger) {
    static std::mutex initMutex;
    std::unique_lock initLock(initMutex);

    if(initialised) {
        return true;
    }

    if(!glfwInit()) {
        logger.addError("Failed to initialise GLFW.");
    } else {
        initialised = true;
    }

    return initialised;
}

bool NLUT::GLFWInitialized() {
    return initialised;
}

void NLUT::claimContext(GLFWwindow *window) {
    contextMutex.lock();

    glfwMakeContextCurrent(window);
}

void NLUT::releaseContext() {
    contextMutex.unlock();
}