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

}

} // namespace lest
