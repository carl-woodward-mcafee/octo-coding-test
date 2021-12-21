cmake_minimum_required(VERSION 3.0.0)
project(sdet-coding-test VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Get gtest and force shared crt.
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/9a32aee22d771387c494be2d8519fbdf46a713b2.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Build with C++ 20.
add_executable(sdet-coding-test main.cpp file_io.cpp file_io_tests.cpp)
target_include_directories(sdet-coding-test PUBLIC 
    ../include 
    ../submodules/google-googletest/googletest/include
    )
target_compile_features(sdet-coding-test PUBLIC cxx_std_20)
target_link_libraries(sdet-coding-test gtest)