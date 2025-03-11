#include "internal/lest-internal.h"

namespace lest
{
namespace testing
{

UnitTest *UnitTest::GetAllInstance()
{
    static UnitTest instance;
    return &instance;
}

UnitTestImpl *UnitTest::impl()
{
    return impl_;
}

UnitTest::UnitTest()
{
}

int UnitTest::Run()
{
    return impl()->Run();
}

int UnitTestImpl::RegisterTest()
{
    return 0;
}

int UnitTestImpl::Run()
{
    
    return 0;
}


} // namespace testing
} // namespace lest
