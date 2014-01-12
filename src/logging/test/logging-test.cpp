#define BOOST_TEST_MODULE logging_logging
#include <boost/test/unit_test.hpp>
#include "logging/logging.h"

BOOST_AUTO_TEST_CASE(LogString) {
    Logging::log(Logging::Level::TRACE, "LogString", "This is a TRACE string");
    Logging::log(Logging::Level::DEBUG, "LogString", "This is a DEBUG string");
    Logging::log(Logging::Level::INFO, "LogString", "This is a INFO string");
    Logging::log(Logging::Level::WARN, "LogString", "This is a WARN string");
    Logging::log(Logging::Level::ERROR, "LogString", "This is a ERROR string");
}


BOOST_AUTO_TEST_CASE(LogFunction) {
    Logging::log(Logging::Level::TRACE, "LogString", [](){ return "This is a TRACE string";});
    Logging::log(Logging::Level::DEBUG, "LogString", [](){ return "This is a DEBUG string";});
    Logging::log(Logging::Level::INFO, "LogString", [](){ return "This is a INFO string";});
    Logging::log(Logging::Level::WARN, "LogString", [](){ return "This is a WARN string";});
    Logging::log(Logging::Level::ERROR, "LogString", [](){ return "This is a ERROR string";});
}


