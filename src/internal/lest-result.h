#include <cstdint>
#include <string>

namespace lest
{
namespace result
{
class TestResult
{
public:
    TestResult();

public:
    bool is_passed_ = true;
    std::string test_group_;
    std::string test_name_;
    std::string error_line_;
};

};

};