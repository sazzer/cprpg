#include <boost/test/unit_test.hpp>
#include "vfs/root.h"

BOOST_AUTO_TEST_CASE(Root_DefaultConstructor) {
    VFS::Root root;
    BOOST_CHECK(VFS::Root::Type::UNKNOWN == root.type());
    BOOST_CHECK_EQUAL("", root.root());
    BOOST_CHECK_EQUAL(0, root.priority());
}

BOOST_AUTO_TEST_CASE(Root_SetValues) {
    VFS::Root root;
    root.type(VFS::Root::Type::DIRECTORY);
    root.root("/tmp");
    root.priority(10);
    BOOST_CHECK(VFS::Root::Type::DIRECTORY == root.type());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());
}

BOOST_AUTO_TEST_CASE(Root_Copy) {
    VFS::Root original;
    original.type(VFS::Root::Type::DIRECTORY);
    original.root("/tmp");
    original.priority(10);

    VFS::Root root(original);
    BOOST_CHECK(VFS::Root::Type::DIRECTORY == root.type());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK(VFS::Root::Type::DIRECTORY == original.type());
    BOOST_CHECK_EQUAL("/tmp", original.root());
    BOOST_CHECK_EQUAL(10, original.priority());
}

BOOST_AUTO_TEST_CASE(Root_Assign) {
    VFS::Root original;
    original.type(VFS::Root::Type::DIRECTORY);
    original.root("/tmp");
    original.priority(10);

    VFS::Root root = original;
    BOOST_CHECK(VFS::Root::Type::DIRECTORY == root.type());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK(VFS::Root::Type::DIRECTORY == original.type());
    BOOST_CHECK_EQUAL("/tmp", original.root());
    BOOST_CHECK_EQUAL(10, original.priority());
}

BOOST_AUTO_TEST_CASE(Root_Move) {
    VFS::Root original;
    original.type(VFS::Root::Type::DIRECTORY);
    original.root("/tmp");
    original.priority(10);

    VFS::Root root(std::move(original));
    BOOST_CHECK(VFS::Root::Type::DIRECTORY == root.type());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK(VFS::Root::Type::UNKNOWN == original.type());
    BOOST_CHECK_EQUAL("", original.root());
    BOOST_CHECK_EQUAL(0, original.priority());
}

BOOST_AUTO_TEST_CASE(Root_MoveAssign) {
    VFS::Root original;
    original.type(VFS::Root::Type::DIRECTORY);
    original.root("/tmp");
    original.priority(10);

    VFS::Root root = std::move(original);
    BOOST_CHECK(VFS::Root::Type::DIRECTORY == root.type());
    BOOST_CHECK_EQUAL("/tmp", root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK(VFS::Root::Type::UNKNOWN == original.type());
    BOOST_CHECK_EQUAL("", original.root());
    BOOST_CHECK_EQUAL(0, original.priority());
}
