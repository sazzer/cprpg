#include <boost/test/unit_test.hpp>
#include "vfs/main/filename.h"

BOOST_AUTO_TEST_CASE(Filename_ConstructFromParts) {
    VFS::Filename filename("core", "assets/logo.png");
    BOOST_CHECK_EQUAL("core", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
}

BOOST_AUTO_TEST_CASE(Filename_ConstructFromString_Rooted) {
    VFS::Filename filename("core:assets/logo.png");
    BOOST_CHECK_EQUAL("core", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
}

BOOST_AUTO_TEST_CASE(Filename_ConstructFromString_Unrooted) {
    VFS::Filename filename("assets/logo.png");
    BOOST_CHECK_EQUAL("", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
}

BOOST_AUTO_TEST_CASE(Filename_ConstructFromString_Unrooted2) {
    VFS::Filename filename(":assets/logo.png");
    BOOST_CHECK_EQUAL("", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
}

BOOST_AUTO_TEST_CASE(Filename_ImplicitConstruct) {
    VFS::Filename filename = std::string("core:assets/logo.png");
    BOOST_CHECK_EQUAL("core", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
}

BOOST_AUTO_TEST_CASE(Filename_ToString_Rooted) {
    VFS::Filename filename("core", "assets/logo.png");
    std::string asString = filename;
    BOOST_CHECK_EQUAL("core:assets/logo.png", asString);
}

BOOST_AUTO_TEST_CASE(Filename_ToString_Unrooted) {
    VFS::Filename filename("", "assets/logo.png");
    std::string asString = filename;
    BOOST_CHECK_EQUAL(":assets/logo.png", asString);
}

BOOST_AUTO_TEST_CASE(Filename_Copy) {
    VFS::Filename original("core", "assets/logo.png");
    VFS::Filename filename(original);
    BOOST_CHECK_EQUAL("core", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
    BOOST_CHECK_EQUAL("core", original.root());
    BOOST_CHECK_EQUAL("assets/logo.png", original.path());
}

BOOST_AUTO_TEST_CASE(Filename_Assign) {
    VFS::Filename original("core", "assets/logo.png");
    VFS::Filename filename = original;
    BOOST_CHECK_EQUAL("core", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
    BOOST_CHECK_EQUAL("core", original.root());
    BOOST_CHECK_EQUAL("assets/logo.png", original.path());
}

BOOST_AUTO_TEST_CASE(Filename_Move) {
    VFS::Filename original("core", "assets/logo.png");
    VFS::Filename filename(std::move(original));
    BOOST_CHECK_EQUAL("core", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
    BOOST_CHECK_EQUAL("", original.root());
    BOOST_CHECK_EQUAL("", original.path());
}

BOOST_AUTO_TEST_CASE(Filename_MoveAssign) {
    VFS::Filename original("core", "assets/logo.png");
    VFS::Filename filename = std::move(original);
    BOOST_CHECK_EQUAL("core", filename.root());
    BOOST_CHECK_EQUAL("assets/logo.png", filename.path());
    BOOST_CHECK_EQUAL("", original.root());
    BOOST_CHECK_EQUAL("", original.path());
}
