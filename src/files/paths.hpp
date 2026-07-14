#pragma once

// Includes from standard
#include <filesystem>

// Includes from third party libraries


// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases

namespace NLUT {
    // Getting/messing with the working directory stuff
    std::filesystem::path getWorkingDir();
    std::filesystem::path getBinaryDir();
    std::filesystem::path getGameDir();

    void setWorkingDir(const std::filesystem::path &path);

    // Create paths from strings
    std::filesystem::path getPath(const std::filesystem::path &dirPath, const std::string &path);
};