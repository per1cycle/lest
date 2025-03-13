#include "internal/lest-internal.h"
#include "internal/lest-define.h"
namespace lest
{
namespace testing
{

UnitTestImpl* UnitTest::impl(){
    return impl_;
}

/**
 * the whole test process only has one UnitTest class
 */
UnitTest::UnitTest()
{
    impl_ = new UnitTestImpl();
    if(debug_)
        std::cout << "UnitTes::Consturctor called\n";
}


UnitTest *UnitTest::GetAllInstance() 
{
    UnitTest instance;

    return &instance;
}

int UnitTest::RegisterTest(Test* test)
{
    return impl()->Register(test);
}   

int UnitTest::RunAllTest()
{
    return impl()->Run();
}

UnitTestImpl::UnitTestImpl()
{
    tests_ = std::vector<Test*>();
    std::cout << "tests_ info in unittest impl init: " << tests_.size() << std::endl;
}

int UnitTestImpl::Register(Test* test)
{
    tests_.push_back(test);
    std::cout << "tests_ info after register test: " << tests_.size() << std::endl;
    return 0;
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
