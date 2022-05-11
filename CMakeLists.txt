cmake_minimum_required(VERSION 3.0.0)
project(teamx-pe-parser VERSION 0.1.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set (CMAKE_POLICY_DEFAULT_CMP0048 NEW)
set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)
add_subdirectory("submodules/googletest")
add_subdirectory("user")