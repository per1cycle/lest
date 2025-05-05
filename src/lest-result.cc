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
    error_line_ = "1";
}

TestResult::TestResult(bool is_passed, std::string test_group, std::string test_name, std::string error_line)
: is_passed_(is_passed), test_group_(test_group), test_name_(test_name), error_line_(error_line)
{
    
}

}

} // namespace lest
