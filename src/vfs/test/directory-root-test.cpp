#include <boost/test/unit_test.hpp>
#include "vfs/directory_root.h"
#include "vfs/test/config.h"

const std::string rootBase = std::string(SOURCE_DIRECTORY) + "/test/vfs/root1";

BOOST_AUTO_TEST_CASE(DirectoryRoot_TestExistsFile) {
    VFS::Roots::Directory root;
    root.name("test");
    root.root(rootBase);
    root.priority(10);

    BOOST_CHECK(root.exists("a/a.txt"));
    BOOST_CHECK(root.exists("b/b.txt"));
    BOOST_CHECK(!root.exists("a/b.txt"));
    BOOST_CHECK(!root.exists("b/a.txt"));
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_TestExistsDirectory) {
    VFS::Roots::Directory root;
    root.name("test");
    root.root(rootBase);
    root.priority(10);

    BOOST_CHECK(root.exists("a"));
    BOOST_CHECK(root.exists("b"));
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_TestLoadFile) {
    VFS::Roots::Directory root;
    root.name("test");
    root.root(rootBase);
    root.priority(10);

    BOOST_CHECK(!root.load("a/b.txt"));
    BOOST_CHECK(!root.load("b/a.txt"));

    auto a = root.load("a/a.txt");
    auto b = root.load("b/b.txt");
    BOOST_CHECK(a);
    BOOST_CHECK(b);
    BOOST_CHECK_EQUAL("This is file A\n", a->readAsText());
    BOOST_CHECK_EQUAL("This is file B\n", b->readAsText());
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_TestLoadDirectory) {
    VFS::Roots::Directory root;
    root.name("test");
    root.root(rootBase);
    root.priority(10);

    BOOST_CHECK(!root.load("a"));
    BOOST_CHECK(!root.load("b"));
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_DefaultConstructor) {
    VFS::Roots::Directory root;
    BOOST_CHECK_EQUAL("", root.name());
    BOOST_CHECK_EQUAL("", root.root());
    BOOST_CHECK_EQUAL(0, root.priority());
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_SetValues) {
    VFS::Roots::Directory root;
    root.name("test");
    root.root(rootBase);
    root.priority(10);
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL(rootBase, root.root());
    BOOST_CHECK_EQUAL(10, root.priority());
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_Copy) {
    VFS::Roots::Directory original;
    original.name("test");
    original.root(rootBase);
    original.priority(10);

    VFS::Roots::Directory root(original);
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL(rootBase, root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK_EQUAL("test", original.name());
    BOOST_CHECK_EQUAL(rootBase, original.root());
    BOOST_CHECK_EQUAL(10, original.priority());
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_Assign) {
    VFS::Roots::Directory original;
    original.name("test");
    original.root(rootBase);
    original.priority(10);

    VFS::Roots::Directory root = original;
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL(rootBase, root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK_EQUAL("test", original.name());
    BOOST_CHECK_EQUAL(rootBase, original.root());
    BOOST_CHECK_EQUAL(10, original.priority());
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_Move) {
    VFS::Roots::Directory original;
    original.name("test");
    original.root(rootBase);
    original.priority(10);

    VFS::Roots::Directory root(std::move(original));
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL(rootBase, root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK_EQUAL("", original.name());
    BOOST_CHECK_EQUAL("", original.root());
}

BOOST_AUTO_TEST_CASE(DirectoryRoot_MoveAssign) {
    VFS::Roots::Directory original;
    original.name("test");
    original.root(rootBase);
    original.priority(10);

    VFS::Roots::Directory root = std::move(original);
    BOOST_CHECK_EQUAL("test", root.name());
    BOOST_CHECK_EQUAL(rootBase, root.root());
    BOOST_CHECK_EQUAL(10, root.priority());

    BOOST_CHECK_EQUAL("", original.name());
    BOOST_CHECK_EQUAL("", original.root());
}

