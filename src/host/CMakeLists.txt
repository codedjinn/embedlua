cmake_minimum_required(VERSION 3.0.0)
project(host VERSION 0.1.0)

set(SFML_STATIC_LIBRARIES TRUE)

add_compile_definitions(SFML_STATIC)

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
    framework/Logger.h
    framework/Logger.cpp
    framework/Vector2.h
    framework/GameObjectDef.h
    framework/GameObjectDef.cpp
    framework/GameObject.h
    framework/GameObject.cpp
    framework/GameObjectFactory.h
    framework/GameObjectFactory.cpp
    framework/GameInstance.h
    framework/GameInstance.cpp
    framework/Map.h
    framework/Map.cpp
    framework/Player.h
    framework/Player.cpp
    framework/Keyboard.h
)

add_executable(host ${SOURCE_FILES})

include_directories(lib/lua/include)
include_directories(lib/json/includes)
include_directories(../SFML2/include)

find_library(LUA lua54 lib/lua)
target_link_libraries(host LINK_PUBLIC ${LUA})

find_library(SFML2 sfml-graphics ../SFML2/lib)
target_link_libraries(host LINK_PUBLIC ${SFML2})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
