#ifndef CPRPG_LOGGING_LOGGING_H
#define CPRPG_LOGGING_LOGGING_H

#include "logging/level.h"
#include <functional>
#include <string>
#include <boost/format.hpp>

namespace Logging {
    /**
     * Write a log message out
     * @param level The level to write at
     * @param group The group to write to
     * @param message The message to write
     */
    void log(const Level& level, const std::string& group, const std::string& message);
    /**
     * Write a log message out
     * @param level The level to write at
     * @param group The group to write to
     * @param message The message to write
     */
    void log(const Level& level, const std::string& group, const boost::format& message);
}

#endif
