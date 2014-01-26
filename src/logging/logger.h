#ifndef CPRPG_LOGGING_LOGGER_H
#define CPRPG_LOGGING_LOGGER_H

#include "logging/level.h"
#include <functional>
#include <string>
#include <boost/format.hpp>

namespace Logging {
    /**
     * Class to make logging even easier
     */
    class Logger {
        public:
            /**
             * Construct the logger
             */
            Logger(const std::string& group);
            /**
             * No copy constructor
             */
            Logger(const Logger& other) = delete;
            /**
             * No move constructor
             */
            Logger(const Logger&& other) = delete;

            /**
             * Write a log message out
             * @param level The level to write at
             * @param message The message to write
             */
            void operator()(const Level& level, const std::string& message) const;
            /**
             * Write a log message out
             * @param level The level to write at
             * @param message The message to write
             */
            void operator()(const Level& level, const boost::format& message) const;
        protected:
        private:
            std::string group_;
    };
}
#endif
