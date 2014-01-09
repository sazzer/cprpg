#define BOOST_TEST_MODULE cprpg
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(PassTest) {
    BOOST_CHECK_EQUAL(10, 2 * 5);
}

BOOST_AUTO_TEST_CASE(FailTest) {
    BOOST_CHECK_EQUAL(10, 3 * 5);
}
