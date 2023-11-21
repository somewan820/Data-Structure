cmake_minimum_required(VERSION 3.20.0)
project(proj_first VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(proj_first main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
