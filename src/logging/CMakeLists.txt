PROJECT (CPRPG_LOGGING)

FILE(GLOB_RECURSE Sources "main/*.cpp")
FILE(GLOB_RECURSE Tests "test/*.cpp")

STRING(REPLACE ";" " " SourcesAsString "${Sources}")
IF (NOT "${SourcesAsString}" STREQUAL "")
    ADD_LIBRARY(cprpg_logging SHARED ${Sources})
    add_cppcheck(cprpg_logging)

    STRING(REPLACE ";" " " TestsAsString "${Tests}")
    IF (NOT "${TestsAsString}" STREQUAL "")
        ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

        ADD_EXECUTABLE(logging_test ${Tests})
        TARGET_LINK_LIBRARIES(logging_test ${Boost_LIBRARIES})
        TARGET_LINK_LIBRARIES(logging_test cprpg_logging)

        ENABLE_TESTING()
        ADD_TEST(CPRPG_LOGGING logging_test)
    ENDIF()
ENDIF()

