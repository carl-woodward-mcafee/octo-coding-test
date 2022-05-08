#include "wil/resource.h"

#include "FileProcessingUtil.h"

bool FileProcessingUtil::mbExit = false;
linkList<FilePid> FileProcessingUtil::fileAndPidList;
wil::unique_handle FileProcessingUtil::startFileProcessEvent;

std::wstring FileProcessingUtil::getFileAttributes(DWORD dwFileAttrs) 
{
    std::wstring strAttributes;

    if (dwFileAttrs & FILE_ATTRIBUTE_ARCHIVE)
        strAttributes += L" | Archive |";

    if (dwFileAttrs & FILE_ATTRIBUTE_COMPRESSED)
        strAttributes += L" | Compressed |";

    if (dwFileAttrs & FILE_ATTRIBUTE_DEVICE)
        strAttributes += L" | Device |";

    if (dwFileAttrs & FILE_ATTRIBUTE_DIRECTORY)
        strAttributes += L" | Directory |";

    if (dwFileAttrs & FILE_ATTRIBUTE_ENCRYPTED)
        strAttributes += L" | Encrypted |";

    if (dwFileAttrs & FILE_ATTRIBUTE_HIDDEN)
        strAttributes += L" | Hidden |";

    if (dwFileAttrs & FILE_ATTRIBUTE_INTEGRITY_STREAM)
        strAttributes += L" | Integrity Stream |";

    if (dwFileAttrs & FILE_ATTRIBUTE_NORMAL)
        strAttributes += L" | Normal |";

    if (dwFileAttrs & FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)
        strAttributes += L" | Content Indexed |";

    if (dwFileAttrs & FILE_ATTRIBUTE_NO_SCRUB_DATA)
        strAttributes += L" | No Scrub Data |";

    if (dwFileAttrs & FILE_ATTRIBUTE_OFFLINE)
        strAttributes += L" | Offline |";

    if (dwFileAttrs & FILE_ATTRIBUTE_READONLY)
        strAttributes += L" | Read Only |";

    if (dwFileAttrs & FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS)
        strAttributes += L" | Recall on Data Access |";

    if (dwFileAttrs & FILE_ATTRIBUTE_RECALL_ON_OPEN)
        strAttributes += L" | Recall on Open |";

    if (dwFileAttrs & FILE_ATTRIBUTE_REPARSE_POINT)
        strAttributes += L" | Reparse Point |";

    if (dwFileAttrs & FILE_ATTRIBUTE_SPARSE_FILE)
        strAttributes += L" | Sparse file |";

    if (dwFileAttrs & FILE_ATTRIBUTE_SYSTEM)
        strAttributes += L" | System |";

    if (dwFileAttrs & FILE_ATTRIBUTE_TEMPORARY)
        strAttributes += L" | Temporary |";

    if (dwFileAttrs & FILE_ATTRIBUTE_VIRTUAL)
        strAttributes += L" | Virtual |";

    return strAttributes;
}

void FileProcessingUtil::initEvents()
{
    startFileProcessEvent.reset(CreateEvent(NULL, FALSE, FALSE, L"FileProcessingEvent"));
}

void FileProcessingUtil::printFileAttributes(std::wstring const& path, uint32_t pid)
{
    DWORD fileAttrs = INVALID_FILE_ATTRIBUTES;

    if (INVALID_FILE_ATTRIBUTES == (fileAttrs = GetFileAttributes(path.c_str())))
    {
        printf(
            "Error: Error getting file attributes for file %ls: Reason: %d \n",
            path.c_str(),
            GetLastError());
    }
    else
    {
        printf(
            "File attributes for file %ls(Pid:%d) Attributes: %x (%ls): \n",
            path.c_str(),
            pid,
            fileAttrs,
            FileProcessingUtil::getFileAttributes(fileAttrs).c_str());
    }
}