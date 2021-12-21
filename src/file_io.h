#include <string_view>
#include <vector>

namespace mcafee::file_io::inline v1
{
std::tuple<uint32_t, void*> create_file(
    std::wstring_view const& path,
    uint32_t desired_access,
    uint32_t share_access,
    uint32_t create_disposition,
    uint32_t flags) noexcept;

std::tuple<uint32_t, std::vector<uint8_t>> read_file(
    void* handle, uint32_t offset, uint32_t length) noexcept;

std::tuple<uint32_t, uint32_t> write_file(
    void* handle, uint32_t offset, std::vector<uint8_t> data) noexcept;

uint32_t close_handle(void* handle) noexcept;

uint32_t delete_file(std::wstring_view const& path) noexcept;

} // namespace mcafee::file_io::inline v1
