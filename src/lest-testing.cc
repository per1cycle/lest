#include "internal/lest-testing.h"

namespace lest
{
namespace testing
{
Test::Test()
{

}

Test::Test(const std::string& test_group, const std::string& test_name)
    : test_group_(test_group), test_name_(test_name)
{

}

TestInfo::TestInfo()
{
    
}

} // namespace testing

} // namespace lest
