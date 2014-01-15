#include <boost/test/unit_test.hpp>
#include "vfs/main/files/disk.h"
#include "vfs/test/config.h"

const std::string rootBase = std::string(SOURCE_DIRECTORY) + "/test/vfs/root1";
const std::string filename = rootBase + "/a/a.txt";

BOOST_AUTO_TEST_CASE(DiskFile_FileNameReturned) {
    VFS::Files::Disk file(filename);
    BOOST_CHECK_EQUAL(filename, file.filename());
}

BOOST_AUTO_TEST_CASE(DiskFile_Open) {
    VFS::Files::Disk file(filename);
    auto stream = file.open();
    BOOST_REQUIRE(stream);
    BOOST_CHECK(stream->good());
}

BOOST_AUTO_TEST_CASE(DiskFile_Read) {
    VFS::Files::Disk file(filename);
    std::string text = file.readAsText();
    BOOST_CHECK_EQUAL("This is file A\n", text);
}
