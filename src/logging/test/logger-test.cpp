#include <boost/test/unit_test.hpp>
#include "logging/logger.h"

BOOST_AUTO_TEST_CASE(Logger_LogString) {
    Logging::Logger LOG("LogString");

    LOG(Logging::Level::TRACE, "This is a TRACE string");
    LOG(Logging::Level::DEBUG, "This is a DEBUG string");
    LOG(Logging::Level::INFO, "This is a INFO string");
    LOG(Logging::Level::WARN, "This is a WARN string");
    LOG(Logging::Level::ERROR, "This is a ERROR string");
}


BOOST_AUTO_TEST_CASE(Logger_LogFunction) {
    Logging::Logger LOG("LogFunction");

    LOG(Logging::Level::TRACE, [](){ return "This is a TRACE string";});
    LOG(Logging::Level::DEBUG, [](){ return "This is a DEBUG string";});
    LOG(Logging::Level::INFO, [](){ return "This is a INFO string";});
    LOG(Logging::Level::WARN, [](){ return "This is a WARN string";});
    LOG(Logging::Level::ERROR, [](){ return "This is a ERROR string";});
}


