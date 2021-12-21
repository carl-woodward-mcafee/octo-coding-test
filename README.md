# McAfee MFESEC SDET Coding Test
The goal of this coding test is to write a unit test that will stress a critical API 'McAfeeCreateFile' that opens a file using an interface similar to [ntdll!NtCreateFile](https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) but removes some of the more cumbersome Windows Native API constructs like OBJECT_ATTRIBUTES rather than a flat path.

Candidates should spend no more than 2 hours on this test and list any test cases that could not be convered in comments in the source file. The candidate can create as many unit test cases as they deem necessary to meet the challenge. The number of tests produced by the candidate is less important is less important than rigor and correctness of the unit tests.


## Requirements
To complete this coding test candidates must be familiar with C++, CMake, Windows APIs, and GTest. Tests must be executable on Windows 10 and Windows 11.

We recommend the following toolset:
* Compilers: Visual Studion 2019 >= 16.11.7 or LLVM (clang) > 13.0.0
* CMake: Version > 3.22.1
* Visual Studio Code: > Version 1.63.1

## Expectations
There is no definitive answer for this coding test. The candidate must write unit tests that validate the file can be opened correctly and determine that expected errors are returned by the API. Examples of areas that need formal testing include path format and share flags.