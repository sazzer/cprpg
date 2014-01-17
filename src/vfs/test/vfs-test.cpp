#include <boost/test/unit_test.hpp>
#include "vfs/directory_root.h"
#include "vfs/vfs.h"
#include "vfs/test/config.h"

const std::string rootBase = std::string(SOURCE_DIRECTORY) + "/test/vfs/root1";

BOOST_AUTO_TEST_CASE(VFS_TestExistsFile) {
    std::shared_ptr<VFS::Root> root(new VFS::Roots::Directory);
    root->name("test");
    root->root(rootBase);
    root->priority(10);

    VFS::VFS vfs;
    vfs.addRoot(root);

    BOOST_CHECK(vfs.exists(std::string("a/a.txt")));
    BOOST_CHECK(vfs.exists(std::string("b/b.txt")));
    BOOST_CHECK(!vfs.exists(std::string("a/b.txt")));
    BOOST_CHECK(!vfs.exists(std::string("b/a.txt")));
}

BOOST_AUTO_TEST_CASE(VFS_TestExistsDirectory) {
    std::shared_ptr<VFS::Root> root(new VFS::Roots::Directory);
    root->name("test");
    root->root(rootBase);
    root->priority(10);

    VFS::VFS vfs;
    vfs.addRoot(root);

    BOOST_CHECK(vfs.exists(std::string("a")));
    BOOST_CHECK(vfs.exists(std::string("b")));
    BOOST_CHECK(!vfs.exists(std::string("c")));
}

BOOST_AUTO_TEST_CASE(VFS_TestLoadFile) {
    std::shared_ptr<VFS::Root> root(new VFS::Roots::Directory);
    root->name("test");
    root->root(rootBase);
    root->priority(10);

    VFS::VFS vfs;
    vfs.addRoot(root);

    BOOST_CHECK(!vfs.load(std::string("a/b.txt")));
    BOOST_CHECK(!vfs.load(std::string("b/a.txt")));

    auto a = vfs.load(std::string("a/a.txt"));
    auto b = vfs.load(std::string("b/b.txt"));
    BOOST_CHECK(a);
    BOOST_CHECK(b);
    BOOST_CHECK_EQUAL("This is file A\n", a->readAsText());
    BOOST_CHECK_EQUAL("This is file B\n", b->readAsText());
}

BOOST_AUTO_TEST_CASE(VFS_TestLoadDirectory) {
    std::shared_ptr<VFS::Root> root(new VFS::Roots::Directory);
    root->name("test");
    root->root(rootBase);
    root->priority(10);

    VFS::VFS vfs;
    vfs.addRoot(root);

    BOOST_CHECK(!vfs.load(std::string("a")));
    BOOST_CHECK(!vfs.load(std::string("b")));
}
