#!/bin/bash

pushd `dirname $0`/.. > /dev/null
SRC_DIR=`pwd`
popd > /dev/null

MODULE_NAME=$1
if [ -z "$MODULE_NAME" ]; then
    echo "Usage: $0 <module-name>";
    exit 1;
fi

PROJECT_NAME=${MODULE_NAME^^}
LIBRARY_NAME=${MODULE_NAME,,}
MODULE_DIR="$SRC_DIR/src/$MODULE_NAME"

echo -n "Creating directory structure        "
if [ -d $MODULE_DIR ]; then
    echo "[31mFailed. Already exists[0m"
else
    mkdir -p $MODULE_DIR
    mkdir -p $MODULE_DIR/main
    mkdir -p $MODULE_DIR/test
    echo "[32mDone[0m"
fi

echo -n "Creating base test file             "
if [ -f "$MODULE_DIR/test/test.cpp" ]; then
    echo "[31mFailed. test.cpp already exists[0m"
else
    if grep -r BOOST_TEST_MODULE $MODULE_DIR/test > /dev/null; then
        echo "[31mFailed. Test file with BOOST_TEST_MODULE already exists[0m"
    else
        cat >> $MODULE_DIR/test/test.cpp << __EOF__
#define BOOST_TEST_MODULE CPRPG_$PROJECT_NAME
#include <boost/test/unit_test.hpp>
__EOF__
    echo "[32mDone[0m"
    fi
fi

echo -n "Creating Build file                 "

if [ -f $MODULE_DIR/CMakeLists.txt ]; then
    echo "[31mFailed. Already exists[0m"
else
    cat >> $MODULE_DIR/CMakeLists.txt << __EOF__
PROJECT (CPRPG_$PROJECT_NAME)

FILE(GLOB_RECURSE Sources "main/*.cpp")
FILE(GLOB_RECURSE Tests "test/*.cpp")

STRING(REPLACE ";" " " SourcesAsString "\${Sources}")
IF (NOT "\${SourcesAsString}" STREQUAL "")
    ADD_LIBRARY(cprpg_${LIBRARY_NAME} SHARED \${Sources})

    STRING(REPLACE ";" " " TestsAsString "\${Tests}")
    IF (NOT "\${TestsAsString}" STREQUAL "")
        ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

        ADD_EXECUTABLE(${LIBRARY_NAME}_test \${Tests})
        TARGET_LINK_LIBRARIES(${LIBRARY_NAME}_test \${Boost_LIBRARIES})
        TARGET_LINK_LIBRARIES(${LIBRARY_NAME}_test cprpg_${LIBRARY_NAME})

        ENABLE_TESTING()
        ADD_TEST(CPRPG_${PROJECT_NAME} ${LIBRARY_NAME}_test)
    ENDIF()
ENDIF()
__EOF__
    echo "[32mDone[0m"
fi


echo -n "Adding to main build file           "
if grep "ADD_SUBDIRECTORY(\"src/${MODULE_NAME}\")" $SRC_DIR/CMakeLists.txt > /dev/null; then
    echo "[31mFailed. Already exists[0m"
else
    echo "ADD_SUBDIRECTORY(\"src/${MODULE_NAME}\")" >> $SRC_DIR/CMakeLists.txt
    echo "[32mDone[0m"
fi
