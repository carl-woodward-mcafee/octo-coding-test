#include "notifications.h"

#include "wil/resource.h"

#include <Windows.h>

bool notify_callback(std::wstring const& path, uint32_t pid)
{
    //
    // McAfee Code Test Candidate. This is the function you must edit. You do not need to run or
    // test this code but it must compile before submission. Please see README.md for details.
    //

    return true;
}

int main(int argc, char** argv)
{
    printf("starting\n");

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

    printf("succeeded\n");
    return 0;
}
