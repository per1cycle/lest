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
    TestResult(bool is_pass, std::string test_group, std::string test_name);
    bool is_passed();
    std::string test_group();
    std::string test_name();

public:
    bool is_passed_ = true;
    std::string test_group_;
    std::string test_name_;
    // std::string error_line_;
};

};

};