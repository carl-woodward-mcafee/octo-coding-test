cmake_minimum_required(VERSION 3.0.0)
project(user-octo-coding-tes VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Build with C++ 20.
add_executable(user-octo-coding-test main.cpp)
target_include_directories(user-octo-coding-test PUBLIC 
    ../submodules/googletest/googletest/include
    ../submodules/wil/include
    )
target_compile_features(user-octo-coding-test PUBLIC cxx_std_20)
target_link_libraries(user-octo-coding-test gtest)