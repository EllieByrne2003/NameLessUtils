#include "paths.hpp"

// Includes from standard
#include <cassert>
#include <iostream>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <limits.h>
#endif

// Includes from third party libraries


// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases


std::filesystem::path NLUT::getWorkingDir() {
    return std::filesystem::current_path();
}

std::filesystem::path NLUT::getBinaryDir() {
#ifdef _WIN32
    char path[MAX_PATH];
    GetModuleFileName(nullptr, path, MAX_PATH);
    return std::filesystem::path(path).parent_path();
#else
    char path[PATH_MAX];
    const int len = readlink("/proc/self/exe", path, PATH_MAX -1);
    if(len != -1) {
        path[len] = '\0';
    } else {
        assert(false);
    }
    return std::filesystem::path(path).parent_path();
#endif
}

std::filesystem::path NLUT::getGameDir() {
    return getBinaryDir().parent_path();
}

void NLUT::setWorkingDir(const std::filesystem::path &path) {
    std::filesystem::current_path(path);
}

// Assumes project root is working directory
std::filesystem::path NLUT::getPath(const std::filesystem::path &dirPath, const std::string &path) {
    // '/' is treated as the project root
    if(path[0] == '/') {
        std::cout << "reading: " << std::filesystem::path(path.c_str() + 1) << std::endl;
        return std::filesystem::path(path.c_str() + 1);
    } else {
        std::cout << "reading: " << dirPath / std::filesystem::path(path) << std::endl;
        return dirPath / std::filesystem::path(path);
    }
}