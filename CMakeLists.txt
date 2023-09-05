cmake_minimum_required(VERSION 3.12)
project(shortestPath VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

add_executable(shortestPath
    main.cpp
    src/ShortestPath.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include_directories(include
    ../ads/include
)

set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_STANDARD 20)
target_compile_options(shortestPath PRIVATE "-fconcepts")
