#include "internal/lest-internal.h"

namespace lest
{
namespace testing
{
bool UnitTest::debug_ = std::getenv("DEBUG");

UnitTestImpl* UnitTest::impl_ = new UnitTestImpl();

UnitTestImpl* UnitTest::impl(){
    return impl_;
}

/**
 * the whole test process only has one UnitTest class
 */
UnitTest::UnitTest()
{
    if(UnitTest::debug_)
        std::cout << "UnitTes::Consturctor called\n";
}

Test* UnitTest::RegisterTest(Test* test) 
{
    return impl()->Register(test);
}

UnitTestImpl *UnitTest::GetAllInstance() 
{
    return impl();
}

int UnitTest::RunAllTest()
{
    return impl()->Run();
}

UnitTestImpl::UnitTestImpl()
{
    if(UnitTest::debug_)
        std::cout << "UnitTestImpl::Constructor called\n";
}

Test* UnitTestImpl::Register(Test* test)
{
    if(UnitTest::debug_)
        std::cout << "UnitTestImpl::Register called\n";
    tests_.push_back(test);
    return nullptr;
}

int UnitTestImpl::Run()
{
    int success_count = 0;
    int failed_count = 0;
    int skip_count = 0;

    for (std::vector<Test*>::iterator it;
         it != tests_.end(); 
         it++)
    {

    }
    
    return 0;
}


} // namespace testing
} // namespace lest
