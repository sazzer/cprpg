#include "logging/logging.h"
#include <iostream>
#include <chrono>
#include <ctime>

namespace Logging {
    /**
     * Method to write the name of the given logging level to the output stream
     * @param os The output stream to write to
     * @param level The level to write
     * @return the output stream
     */
    std::ostream& operator<<(std::ostream& os, const Level& level) {
        switch (level) {
            case Level::TRACE: os << "TRACE"; break;
            case Level::DEBUG: os << "DEBUG"; break;
            case Level::INFO:  os << "INFO"; break;
            case Level::WARN:  os << "WARN"; break;
            case Level::ERROR: os << "ERROR"; break;
        }
        return os;
    }

    /**
     * Write a log message out
     * @param level The level to write at
     * @param group The group to write to
     * @param message The message to write
     */
    void log(const Level& level, const char* group, const char* message) {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);

        std::cerr.width(10);
        std::cerr.flags(std::ios::left);
        std::cerr << level;

        std::cerr.width(20);
        std::cerr.flags(std::ios::left | std::ios::dec);
        std::cerr << now_c;

        std::cerr << "[" << group << "] " << message << std::endl;
    }
    /*
     * Write a log message out, as returned by the provided function
     * @param level The level to write at
     * @param group The group to write to
     * @param message The function to generate the message to write
     */
    void log(const Level& level, const char* group, std::function<const char*()> message) {
        log(level, group, message());
    }
}
