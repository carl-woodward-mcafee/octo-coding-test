#include <functional>
#include <Windows.h>

using fs_notify_callback_t = std::function<bool(std::wstring const&, uint32_t)>;

//! @brief
//! @param cb
//! @param stop_handle
//! @return
int register_for_fs_notifications(
    [[maybe_unused]] fs_notify_callback_t cb, [[maybe_unused]] HANDLE stop_handle)
{
    // This is a stub function and doesn't do anything. It is only here to make the exercise feel
    // more real.
    return true;
}
