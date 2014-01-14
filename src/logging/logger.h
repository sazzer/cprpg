#ifndef CPRPG_LOGGING_LOGGER_H
#define CPRPG_LOGGING_LOGGER_H

#include "logging/level.h"
#include <functional>
#include <string>

namespace Logging {
    /**
     * Class to make logging even easier
     */
    class Logger {
        public:
            /**
             * Construct the logger
             */
            Logger(const char* group);
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
            void operator()(const Level& level, const char* message) const;
            /**
             * Write a log message out, as returned by the provided function
             * @param level The level to write at
             * @param message The function to generate the message to write
             */
            void operator()(const Level& level, std::function<const char*()> message) const;
        protected:
        private:
            std::string group_;
    };
}
#endif
