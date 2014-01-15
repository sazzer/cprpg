PROJECT (CPRPG_VFS)

FILE(GLOB_RECURSE Sources "main/*.cpp")
FILE(GLOB_RECURSE Tests "test/*.cpp")

ADD_LIBRARY(cprpg_vfs SHARED ${Sources})
TARGET_LINK_LIBRARIES(cprpg_vfs ${Boost_SYSTEM_LIBRARIES})
TARGET_LINK_LIBRARIES(cprpg_vfs ${Boost_FILESYSTEM_LIBRARIES})
add_cppcheck(cprpg_vfs)

CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/test/config.h.in" "${PROJECT_BINARY_DIR}/vfs/test/config.h")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

STRING(REPLACE ";" " " TestsAsString "${Tests}")
IF (NOT "${TestsAsString}" STREQUAL "")
    ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

    ADD_EXECUTABLE(vfs_test ${Tests})
    TARGET_LINK_LIBRARIES(vfs_test ${Boost_LIBRARIES})
    TARGET_LINK_LIBRARIES(vfs_test cprpg_vfs)

    ENABLE_TESTING()
    ADD_TEST(CPRPG_VFS vfs_test)
ENDIF()
