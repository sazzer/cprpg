#define BOOST_TEST_MODULE vfs_file
#include <boost/test/unit_test.hpp>
#include "vfs/file.h"

BOOST_AUTO_TEST_CASE(FileNameReturned) {
    VFS::File file("/tmp/hello");
    BOOST_CHECK_EQUAL("/tmp/hello", file.filename());
}

