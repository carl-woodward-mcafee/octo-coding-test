#pragma once
#include <string>

struct FilePid
{

    FilePid(std::wstring const& path, uint32_t pid) 
    { 
        mFileNameWithPath = path;
        mPid = pid;
    }

 
    std::wstring mFileNameWithPath;
    uint32_t mPid;

};