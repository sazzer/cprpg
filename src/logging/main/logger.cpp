#include "logging/logger.h"
#include "logging/logging.h"

namespace Logging {
    Logger::Logger(const std::string& group) : group_(group) {
    }
    /**
     * Write a log message out
     * @param level The level to write at
     * @param message The message to write
     */
    void Logger::operator()(const Level& level, const std::string& message) const {
        Logging::log(level, group_.c_str(), message);
    }
    /**
     * Write a log message out
     * @param level The level to write at
     * @param message The message to write
     */
    void Logger::operator()(const Level& level, const boost::format& message) const {
        Logging::log(level, group_.c_str(), message.str());
    }
}
