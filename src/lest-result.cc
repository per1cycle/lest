#include <internal/lest-result.h>

namespace lest
{
namespace result
{
TestResult::TestResult()
{
    is_passed_ = true;
    test_group_ = "Default group";
    test_name_ = "Default name";
    // error_line_ = "1";
}

TestResult::TestResult(bool is_passed, std::string test_group, std::string test_name)
: is_passed_(is_passed), test_group_(test_group), test_name_(test_name)
{
    
}

bool TestResult::is_passed()
{
    return is_passed_;
}

std::string TestResult::test_group()
{
    return test_group_;
}

std::string TestResult::test_name()
{
    return test_name_;
}

}

} // namespace lest
