PROJECT (CPRPG_CPRPG)

FILE(GLOB_RECURSE Sources "main/*.cpp")
FILE(GLOB_RECURSE Tests "test/*.cpp")

ADD_EXECUTABLE(cprpg ${Sources})
