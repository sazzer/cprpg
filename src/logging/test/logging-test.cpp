#include <boost/test/unit_test.hpp>
#include "logging/logging.h"

BOOST_AUTO_TEST_CASE(Logging_LogString) {
    Logging::log(Logging::Level::TRACE, "LogString", "This is a TRACE string");
    Logging::log(Logging::Level::DEBUG, "LogString", "This is a DEBUG string");
    Logging::log(Logging::Level::INFO, "LogString", "This is a INFO string");
    Logging::log(Logging::Level::WARN, "LogString", "This is a WARN string");
    Logging::log(Logging::Level::ERROR, "LogString", "This is a ERROR string");
}
