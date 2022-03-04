# McAfee OCTO Coding Test
This repository provides OCTO coding tests for SDET and Kernel engineers.

## Requirements
To complete these coding tests candidates must be familiar with C++, Windows APIs, and [googletest](https://github.com/google/googletest). Tests must be executable on Windows 10 and Windows 11.

We recommend the following toolset:
* Compilers: [Visual Studio 2019](https://visualstudio.microsoft.com/downloads/) >= 16.11.7 or [LLVM](https://llvm.org) >= 13.0.0
* [Windows SDK](https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/) >= 10.0.22000
* [Windows WDK](https://docs.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk) >= 10.0.2000 and **MUST** be the same version as the Windows SDK installed above.

## Repository Initialization
[Google Test](https://github.com/google/googletest) is supplied as a submodule. Please run the following git command to retrieve the submodule:

```git submodule update --init```

## Build Instructions
Please use Visual Studio 2019 or later and double click on the solution file [octo_coding_test.sln](octo_coding_test.sln). Visual Studio will start and open the solution. If you are asked if you want to upgrade the solutions, chose `Upgrade`.

# The Tests
There are a number of tests in this repository, only do the test that you have been asked to perform.
1. [Software Development Engineer in Test](sdet/README.md)
1. [Kernel Engineer](kernel/README.md)
1. [User Engineer](user/README.md)

Good luck with the test!