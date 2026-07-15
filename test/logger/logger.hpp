#pragma once

// Includes from standard
#include <filesystem>
#include <exception>
#include <fstream>
#include <ostream>
#include <string>
#include <mutex>

// Includes from third party libraries
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Includes from personal libraries


// Includes from project


// Forward declarations


// Type aliases

namespace NLUT {
    class Logger final {
    private:
        std::ostream &output;
        std::ofstream fileOutput; // Only used when passing filepaths

        std::mutex outputMutex;

    protected:

    public:
        Logger(const std::filesystem::path &path);
        Logger(std::ostream &output);
        Logger();
        ~Logger();

        // Successes
        void addSuccess(const std::string &message);

        // Warnings // TODO implement this later
        // void addWarning(const std::string &message);
    
        // void addCastingWarning(const json &j, const std::string &message);

        // Errors
        void addError(const std::exception &e, const std::string &message);
        void addError(const std::string &message);

        void addJsonParseError(const json::exception &e, const std::filesystem::path &path, const std::string &message);
        void addJsonParseError(const json::exception &e, const std::string &content, const std::string &message);

        void addConversionError(const json::exception &e, const json &j, const std::string &message);
        void addConversionError(const json &j, const std::string &message);

        void addFileReadError(const std::filesystem::path &path, const std::string &message);

        void flush();
    };
};