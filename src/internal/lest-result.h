#include <cstdint>
#include <string>

namespace lest
{
namespace result
{
class Result
{
public:
    Result() = delete;

private:
    std::uint32_t m_id = 0;
    std::string test_group_;
    std::string test_name_;
    std::string error_line_;
};

};

};