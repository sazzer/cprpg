PROJECT (CPRPG_VFS)

FILE(GLOB_RECURSE Sources "main/*.cpp")
FILE(GLOB_RECURSE Tests "test/*.cpp")

ADD_LIBRARY(cprpg_vfs SHARED ${Sources})

STRING(REPLACE ";" " " TestsAsString "${Tests}")
IF (NOT "${TestsAsString}" STREQUAL "")
    ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

    ADD_EXECUTABLE(vfs_test ${Tests})
    TARGET_LINK_LIBRARIES(vfs_test ${Boost_LIBRARIES})
    TARGET_LINK_LIBRARIES(vfs_test cprpg_vfs)

    ENABLE_TESTING()
    ADD_TEST(CPRPG_VFS vfs_test)
ENDIF()
