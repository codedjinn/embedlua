cmake_minimum_required(VERSION 3.0.0)
project(host VERSION 0.1.0)

#include(CTest)
# enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

set (CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

set(
    SOURCE_FILES
    main.cpp
    framework/Utils.h
    framework/Utils.cpp
    framework/Logger.h
    framework/Logger.cpp
    framework/GameObjectFactory.h
    framework/GameObjectFactory.cpp
)

add_executable(host ${SOURCE_FILES})

include_directories(lib/lua/include)
include_directories(lib/json/includes)

# include_directories(lib/sdl2/include)

find_library(LUA lua54 lib/lua)
target_link_libraries(host LINK_PUBLIC ${LUA})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
