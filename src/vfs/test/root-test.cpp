#include <boost/test/unit_test.hpp>
#include "vfs/root.h"

/**
 * VFS::Root is pure virtual, so this implements the method we need
 */
class UnitTestRoot : public VFS::Root {
    public:
        bool exists(const std::string& filename) {
            return false;
        }
        std::unique_ptr<VFS::File> load(const std::string& filename) {
            return std::unique_ptr<VFS::File>();
        }
};

BOOST_AUTO_TEST_CASE(Root_DefaultConstructor) {
    UnitTestRoot root;
    BOOST_CHECK_EQUAL("", root.name());
    BOOST_CHECK_EQUAL("", root.root());
    BOOST_CHECK_EQUAL(0, root.priority());
}

BOOST_AUTO_TEST_CASE(Root_SetValues) {
    UnitTestRoot root;
    root.name("test");
    root.root("/tmp");
    root.priority(10);
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());
}

BOOST_AUTO_TEST_CASE(Root_Copy) {
    UnitTestRoot original;
    original.name("test");
    original.root("/tmp");
    original.priority(10);

    UnitTestRoot root(original);
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK_EQUAL("test", original.name());
    BOOST_CHECK_EQUAL("/tmp", original.root());
    BOOST_CHECK_EQUAL(10, original.priority());
}

BOOST_AUTO_TEST_CASE(Root_Assign) {
    UnitTestRoot original;
    original.name("test");
    original.root("/tmp");
    original.priority(10);

    UnitTestRoot root = original;
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK_EQUAL("test", original.name());
    BOOST_CHECK_EQUAL("/tmp", original.root());
    BOOST_CHECK_EQUAL(10, original.priority());
}

BOOST_AUTO_TEST_CASE(Root_Move) {
    UnitTestRoot original;
    original.name("test");
    original.root("/tmp");
    original.priority(10);

    UnitTestRoot root(std::move(original));
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK_EQUAL("", original.name());
    BOOST_CHECK_EQUAL("", original.root());
}

BOOST_AUTO_TEST_CASE(Root_MoveAssign) {
    UnitTestRoot original;
    original.name("test");
    original.root("/tmp");
    original.priority(10);

    UnitTestRoot root = std::move(original);
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK_EQUAL("", original.name());
    BOOST_CHECK_EQUAL("", original.root());
}
