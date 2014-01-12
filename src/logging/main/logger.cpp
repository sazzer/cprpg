#include "logging/logger.h"
#include "logging/logging.h"

namespace Logging {
    Logger::Logger(const char* group) : group_(group) {
    }
    /**
     * Write a log message out
     * @param level The level to write at
     * @param message The message to write
     */
    void Logger::operator()(const Level& level, const char* message) const {
        Logging::log(level, group_.c_str(), message);
    }

    /**
     * Write a log message out, as returned by the provided function
     * @param level The level to write at
     * @param message The function to generate the message to write
     */
    void Logger::operator()(const Level& level, std::function<const char*()> message) const {
        Logging::log(level, group_.c_str(), message);
    }
}
