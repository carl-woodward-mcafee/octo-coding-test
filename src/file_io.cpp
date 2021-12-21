#include "file_io.h"

#include <Windows.h>

namespace mcafee::file_io::inline v1
{
std::tuple<uint32_t, void*> create_file(
    std::wstring_view const& path,
    uint32_t desired_access,
    uint32_t share_mode,
    uint32_t create_disposition,
    uint32_t flags) noexcept
{
    auto handle{
        CreateFile(path.data(), desired_access, share_mode, NULL, create_disposition, 0, NULL)};
    auto success{handle == INVALID_HANDLE_VALUE};
    return {success ? ERROR_SUCCESS : GetLastError(), handle};
}

std::tuple<uint32_t, std::vector<uint8_t>> read_file(
    void* handle, uint32_t offset, uint32_t length) noexcept
{
    auto result = SetFilePointer(handle, offset, NULL, FILE_BEGIN);
    if (result == INVALID_SET_FILE_POINTER)
        return {GetLastError(), {}};

    std::vector<uint8_t> data(length);
    auto data_size = static_cast<uint32_t>(data.size());
    DWORD written{};
    auto success = ReadFile(handle, data.data(), data_size, &written, NULL);
    return {success ? ERROR_SUCCESS : GetLastError(), data};
}

std::tuple<uint32_t, uint32_t> write_file(
    void* handle, uint32_t offset, std::vector<uint8_t> data) noexcept
{
    auto result = SetFilePointer(handle, offset, NULL, FILE_BEGIN);
    if (result == INVALID_SET_FILE_POINTER)
        return {GetLastError(), 0};

    auto data_size = static_cast<uint32_t>(data.size());
    DWORD written{};
    auto success = WriteFile(handle, data.data(), data_size, &written, NULL);
    return {success ? ERROR_SUCCESS : GetLastError(), written};
}

uint32_t close_handle(void* handle) noexcept
{
    auto result = CloseHandle(handle);
    return result ? ERROR_SUCCESS : GetLastError();
}

uint32_t delete_file(std::wstring_view const& path) noexcept
{
    auto result = DeleteFile(path.data());
    return result ? ERROR_SUCCESS : GetLastError();
}

} // namespace mcafee::file_io::inline v1
