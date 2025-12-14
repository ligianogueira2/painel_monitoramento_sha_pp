#include "infra/logger/Logger.hpp"
#include <iostream>
#include <ctime>

// Inicialização dos membros estáticos
Logger* Logger::instance = nullptr;
std::mutex Logger::mtx;

Logger::Logger() {
    logFile.open("pmscha.log", std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "[LOGGER ERROR] Nao foi possível abrir o arquivo de log.\n";
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

Logger& Logger::getInstance() {
    std::lock_guard<std::mutex> lock(mtx);

    if (instance == nullptr) {
        instance = new Logger();
    }
    return *instance;
}

std::string Logger::levelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARN";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::DEBUG: return "DEBUG";
        default: return "UNKNOWN";
    }
}

void Logger::log(LogLevel level, const std::string& message) {
    std::time_t now = std::time(nullptr);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::string finalMessage =
        "[" + std::string(buffer) + "] [" +
        levelToString(level) + "] " + message;

    // Console
    std::cout << finalMessage << std::endl;

    // Arquivo
    if (logFile.is_open()) {
        logFile << finalMessage << std::endl;
    }
}

void Logger::info(const std::string& message) {
    log(LogLevel::INFO, message);
}

void Logger::warn(const std::string& message) {
    log(LogLevel::WARNING, message);
}

void Logger::error(const std::string& message) {
    log(LogLevel::ERROR, message);
}

void Logger::debug(const std::string& message) {
    log(LogLevel::DEBUG, message);
}
