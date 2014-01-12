#ifndef CPRPG_LOGGING_LOGGING_H
#define CPRPG_LOGGING_LOGGING_H

#include "logging/level.h"
#include <functional>

namespace Logging {
    /**
     * Write a log message out
     * @param level The level to write at
     * @param group The group to write to
     * @param message The message to write
     */
    void log(const Level& level, const char* group, const char* message);
    /**
     * Write a log message out, as returned by the provided function
     * @param level The level to write at
     * @param group The group to write to
     * @param message The function to generate the message to write
     */
    void log(const Level& level, const char* group, std::function<const char*()> message);
}

#endif
