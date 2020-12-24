# CMakeList.txt : CMake project for cpp2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(engine VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

set (CMAKE_CXX_STANDARD 11)

set(
    SOURCE_FILES
    src/util.h
    src/logger.h
    src/logger.cpp
    src/lua_value.h
    src/lua_method.h
    src/script_manager.h
    src/script_manager.cpp
    src/entity.h
    main.cpp
)

add_executable(engine ${SOURCE_FILES})

include_directories(lib/lua/include)

find_library(LUA lua lib/lua)
target_link_libraries(engine LINK_PUBLIC ${LUA})