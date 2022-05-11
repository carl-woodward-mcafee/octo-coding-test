#include <functional>
#include <mutex>
#include <condition_variable>

using fs_notify_callback_t = std::function<bool(std::wstring const&, uint32_t)>;

//! @brief Registers for file system notification.
//! @param callback The callback to register.
//! @param stop_cv The condition variable to set when notifications terminate.
//! @param mutex The mutex used to lock the condition variable for when notifications terminate. 
//! @return Always true.
bool register_for_fs_notifications(
    [[maybe_unused]] fs_notify_callback_t cb, [[maybe_unused]] std::condition_variable& cv, [[maybe_unused]] std::mutex& mutex)
{
    // This is a stub function and doesn't do anything. It is only here to make the exercise feel more real.
    return true;
}
