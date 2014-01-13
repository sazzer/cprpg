#include <boost/test/unit_test.hpp>
#include "vfs/main/files/disk.h"

BOOST_AUTO_TEST_CASE(DiskFile_FileNameReturned) {
    VFS::DiskFile file("/tmp/hello");
    BOOST_CHECK_EQUAL("/tmp/hello", file.filename());
}

