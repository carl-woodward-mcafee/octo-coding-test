#include "gtest/gtest.h"
#include "file_io.h"

#include <filesystem>
#include <array>
#include <string_view>

#include <Windows.h>

namespace ntdll
{
#include <winternl.h>
#pragma comment(lib, "ntdll.lib")
} // namespace ntdll

namespace fs = std::filesystem;
namespace file_io = mcafee::file_io;
using namespace std::string_view_literals;

class mcafee_create_file_tests : public ::testing::Test
{
protected:
    void SetUp() override
    {
        auto file_path = fs::current_path();
        file_path.append(LR"(test.txt)");
        text_file_path_ = fs::current_path().append(L"test.txt").generic_wstring().c_str();
    }
    void TearDown() override {}

    std::wstring text_file_path_{};
    std::string_view text_file_contents_{"Write this out and verify it is read back correctly!"sv};
};

TEST_F(mcafee_create_file_tests, create_new_text_file)
{
    auto [result_create, handle] = file_io::create_file(
        text_file_path_, GENERIC_READ | GENERIC_WRITE | DELETE, 0, OPEN_ALWAYS, 0);
    ASSERT_EQ(result_create, ERROR_SUCCESS);

    std::vector<uint8_t> write_data(text_file_contents_.size());
    RtlCopyMemory(write_data.data(), text_file_contents_.data(), text_file_contents_.size());
    auto [write_result, written] = file_io::write_file(handle, 0, write_data);
    ASSERT_EQ(write_result, ERROR_SUCCESS);
    ASSERT_EQ(written, write_data.size());

    auto [result_read, read_data] =
        file_io::read_file(handle, 0, static_cast<uint32_t>(text_file_contents_.size()));
    ASSERT_EQ(result_read, ERROR_SUCCESS);
    ASSERT_EQ(read_data.size(), text_file_contents_.size());

    ASSERT_EQ(write_data.size(), read_data.size());
    ASSERT_EQ(
        RtlCompareMemory(write_data.data(), read_data.data(), read_data.size()), write_data.size());

    ASSERT_EQ(file_io::close_handle(handle), ERROR_SUCCESS);
    ASSERT_EQ(file_io::delete_file(text_file_path_), ERROR_SUCCESS);
}
