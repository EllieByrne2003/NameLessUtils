#include "logger.hpp"

// Includes from standard
#include <iostream>

// Includes from third party libraries


// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases


NLUT::Logger::Logger(const std::filesystem::path &path) : output(fileOutput), fileOutput(path) {

}

NLUT::Logger::Logger(std::ostream &output) : output(output) {

}

NLUT::Logger::Logger() : output(std::cout) {

}

NLUT::Logger::~Logger() {

}

void NLUT::Logger::addSuccess(const std::string &message) {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << "Success: " << message << std::endl;
    output << std::endl;
}

void NLUT::Logger::addError(const std::exception &e, const std::string &message) {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << "Error: " << message << std::endl;
    output << "\tRaw exception: \"" << e.what() << "\"." << std::endl;
    output << std::endl;
}

void NLUT::Logger::addError(const std::string &message) {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << "Error: " << message << std::endl;
    output << std::endl;
}

void NLUT::Logger::addJsonParseError(const json::exception &e, const std::filesystem::path &path, const std::string &message) {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << "Error: " << message << std::endl;
    output << "\tReason: Failed to parse file: \"" << path << "\"." << std::endl;
    output << "\tRaw exception: \"" << e.what() << "\"." << std::endl; 
    output << std::endl;
}

void NLUT::Logger::addJsonParseError(const json::exception &e, const std::string &content, const std::string &message) {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << "Error: " << message << std::endl;
    output << "\tReason: failed to parse string: \"" << content << "\"." << std::endl;
    output << "\tRaw exception: \"" << e.what() << "\"." << std::endl;
    output << std::endl;
}

void NLUT::Logger::addConversionError(const json::exception &e, const json &j, const std::string &message) {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << "Error: " << message << std::endl;
    output << "\tReason: Malformed json object." << std::endl;
    output << "\tMalformed object: " << j << "." << std::endl;
    output << "\tRaw exception: \"" << e.what() << "\"." << std::endl;
    output << std::endl;
}

void NLUT::Logger::addConversionError(const json &j, const std::string &message) {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << "Error: " << message << std::endl;
    output << "\tReason: Malformed json object." << std::endl;
    output << "\tMalformed object: " << j << "." << std::endl;
    output << std::endl;
}

void NLUT::Logger::addFileReadError(const std::filesystem::path &path, const std::string &message) {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << "Error: " << message << std::endl;
    output << "\tReason: Could not open file: " << path << "." << std::endl;
    output << std::endl;
}

void NLUT::Logger::flush() {
    std::unique_lock<std::mutex> outputLock(outputMutex);

    output << std::flush;
}