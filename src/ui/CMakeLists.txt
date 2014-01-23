PROJECT (CPRPG_UI)

FILE(GLOB_RECURSE Sources "main/*.cpp")
FILE(GLOB_RECURSE Tests "test/*.cpp")

STRING(REPLACE ";" " " SourcesAsString "${Sources}")
IF (NOT "${SourcesAsString}" STREQUAL "")
    ADD_LIBRARY(cprpg_ui SHARED ${Sources})
    add_cppcheck(cprpg_ui)

    STRING(REPLACE ";" " " TestsAsString "${Tests}")
    IF (NOT "${TestsAsString}" STREQUAL "")
        ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

        ADD_EXECUTABLE(ui_test ${Tests})
        TARGET_LINK_LIBRARIES(ui_test ${Boost_LIBRARIES})
        TARGET_LINK_LIBRARIES(ui_test cprpg_ui)

        ENABLE_TESTING()
        ADD_TEST(CPRPG_UI ui_test)
    ENDIF()
ENDIF()
