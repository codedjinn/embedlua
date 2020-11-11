cmake_minimum_required(VERSION 3.0.0)
project(host VERSION 0.1.0)

add_definitions(-DSFML_STATIC)

set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

#include(CTest)
# enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

set (CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

set(
    SOURCE_FILES
    main.cpp
    lib/json/jsoncpp.cpp
    framework/Utils.h
    framework/Utils.cpp
    framework/JsonUtils.h
    framework/JsonUtils.cpp
    framework/Lookup.h
    framework/Lookup.cpp
    framework/ServiceManager.h
    framework/ServiceManager.cpp
    framework/Logger.h
    framework/Logger.cpp
    framework/GameObjectDef.h
    framework/GameObjectDef.cpp
    framework/GameObject.h
    framework/GameObject.cpp
    framework/GameObjectFactory.h
    framework/GameObjectFactory.cpp
    framework/GameInstance.h
    framework/GameInstance.cpp
    framework/ScriptManager.h
    framework/ScriptManager.cpp
    framework/Map.h
    framework/Map.cpp
    framework/Player.h
    framework/Player.cpp
    framework/Keyboard.h
)

add_executable(host ${SOURCE_FILES})

include_directories(lib/lua/include)
include_directories(lib/json/includes)
include_directories(C:/sfml2/include)

find_library(LUA lua54 lib/lua)
target_link_libraries(host LINK_PUBLIC ${LUA})

find_library(SFML2 sfml-graphics c:/SFML2/lib)
target_link_libraries(host LINK_PUBLIC ${SFML2})

find_library(SFML22 sfml-window c:/SFML2/lib)
target_link_libraries(host LINK_PUBLIC ${SFML22})

find_library(SFML21 sfml-system c:/SFML2/lib)
target_link_libraries(host LINK_PUBLIC ${SFML21})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
