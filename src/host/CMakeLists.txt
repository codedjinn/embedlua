cmake_minimum_required(VERSION 3.0.0)
project(host VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

set(
    SOURCE_FILES
    main.cpp
    entity.h
)

add_executable(host ${SOURCE_FILES})

include_directories(lib/lua/include)
# include_directories(lib/sdl2/include)

find_library(LUA lua54 lib/lua)
target_link_libraries(host LINK_PUBLIC ${LUA})

# find_library(SDL2Main SDL2main lib/sdl2)
# find_library(SDL2 SDL2 lib/sdl2)

# target_link_libraries(host LINK_PUBLIC ${SDL2Main})
# target_link_libraries(host LINK_PUBLIC ${SDL2})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
