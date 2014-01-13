#include <boost/test/unit_test.hpp>
#include "vfs/file.h"
#include <sstream>

/**
 * VFS::File is pure virtual, so this implements the method we need
 */
class UnitTestFile : public VFS::File {
    public:
        /**
         * Open a stream onto the file for reading
         * @return the stream to read the file with
         */
        virtual std::unique_ptr<std::istream> open() const {
            return std::unique_ptr<std::istream>(new std::istringstream("Hello\nWorld"));
        }
};

BOOST_AUTO_TEST_CASE(File_ReadAsText) {
    UnitTestFile testFile;
    std::string text = testFile.readAsText();
    BOOST_CHECK_EQUAL("Hello\nWorld", text);
}

BOOST_AUTO_TEST_CASE(File_ReadAsBinary) {
    UnitTestFile testFile;
    std::vector<char> binary = testFile.readAsBinary();
    BOOST_CHECK(memcmp("Hello\nWorld", &(binary[0]), binary.size()) == 0);
}

