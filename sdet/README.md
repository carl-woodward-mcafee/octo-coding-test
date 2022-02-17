# SDET Test
The goal of this coding test is to write a unit test that will stress a critical API 'mcafee::file_io::create_file' that opens a file using an interface similar to [kernelbase!CreateFileW](https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) but removes some of the Less commonly used parameters and makes the interface pure C++ (it does not make use of windows headers directly).

Candidates should spend no more than 2 hours on this test and list any test cases that could not be convered in comments in the source file. The candidate can create as many unit test cases as they deem necessary to meet the challenge. The number of tests produced by the candidate is less important than rigor and correctness of the unit tests.

## Task and Expectations
The goal of the exercise to stress test `mcafee::file_io::create_file` api in [file_io.cpp](sdet/file_io.cpp). A sample unit test has been [file_io_tests.cpp](sdet/file_io_tests.cpp) that tests the api allows us to open a file, write to it, read from it, and finally close and delete.

We would like you to write unit tests that will stress the api `mcafee::file_io::create_file` and show that it is currently unsafe and/or verify that the API behaves like `kernelbase!CreateFileW`.

There is no definitive answer for this coding test. The candidate must write unit tests that validate the file can be opened correctly and determine that expected errors are returned by the API. Examples of areas that need formal testing include path format and share flags.