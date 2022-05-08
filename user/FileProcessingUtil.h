#pragma once
#include <memory>
#include <string>
#include "Windows.h"

#include "FilePid.h"
#include "linkList.h"

class FileProcessingUtil
{
public:
    static std::wstring getFileAttributes(DWORD dwFileAttrs);
    static void printFileAttributes(std::wstring const& path, uint32_t pid);
    static void initEvents();

    static bool mbExit;
    static linkList<FilePid> fileAndPidList;
    static wil::unique_handle startFileProcessEvent;
};