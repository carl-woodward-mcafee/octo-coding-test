#include "notifications.h"

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

    std::mutex mutex{};
    std::unique_lock<std::mutex> lock{mutex};
    std::condition_variable cv{};
    if (!register_for_fs_notifications(notify_callback, cv, mutex))
    {
        printf("register_for_fs_notifications failed\n");
        return 2;
    }
    cv.wait(lock);  

    printf("succeeded\n");
    return 0;
}
