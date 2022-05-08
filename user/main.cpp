#include <thread>
#include <mutex>
#include <Windows.h>

#include "notifications.h"
#include "wil/resource.h"

#include "FileProcessingUtil.h"


bool notify_callback(std::wstring const& path, uint32_t pid)
{
    //
    // This method is edited for McAfee Code Test 
    //

    FilePid* newItem = new FilePid(path, pid);
    FileProcessingUtil::fileAndPidList.insert(newItem); // Thread safe template class linked list 

    if (FALSE == SetEvent(FileProcessingUtil::startFileProcessEvent.get()))
    {
        printf("Error: Failed to notify worker thread: Reason: %d \n", GetLastError());
        return false;
    }

    return true;
}

void workerThread(int dummyParam)
{
    FilePid* pItemToProcess = nullptr;
    while (!FileProcessingUtil::mbExit)
    {
        DWORD dwWait = WaitForSingleObject(FileProcessingUtil::startFileProcessEvent.get(), INFINITE);
        if (WAIT_OBJECT_0 == dwWait && !FileProcessingUtil::mbExit)
        {
            // Process all file attribs
            while (nullptr != (pItemToProcess = FileProcessingUtil::fileAndPidList.removeFromTop())) // Thread safe remove from Linked list
            {
                FileProcessingUtil::printFileAttributes(pItemToProcess->mFileNameWithPath, pItemToProcess->mPid);
            }

                delete pItemToProcess;
        }
        else if (!FileProcessingUtil::mbExit)
        {
            printf("Error: Failed on Wait: Reason: %d WaitReturn: %ul\n", GetLastError(), dwWait);
        }
    }
}


int main(int argc, char** argv)
{
    printf("starting\n");
 

    FileProcessingUtil::initEvents();
    std::thread workerThreadObj(workerThread, 10);

    wil::unique_handle stop_event{CreateEvent(NULL, FALSE, FALSE, NULL)};
    if (!stop_event.get())
    {
        printf("failed to create stop event\n");
        return 1;
    }

    if (!register_for_fs_notifications(notify_callback, stop_event.get()))
    {
        printf("register_for_fs_notifications failed\n");
        return 2;
    }

    auto wait_result = WaitForSingleObject(stop_event.get(), INFINITE);
    if (wait_result == WAIT_FAILED)
    {
        printf("WaitForSingleObject failed\n");
        return 3;
    }

    FileProcessingUtil::mbExit = true;
    if (FALSE == SetEvent(FileProcessingUtil::startFileProcessEvent.get()))
    {
        printf("Error: Failed to set worker thread Exit: Reason: %d \n", GetLastError());
        return false;
    }
    workerThreadObj.join();

    printf("succeeded\n");
    return 0;
}


