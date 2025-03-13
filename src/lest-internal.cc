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
        std::cout << "UnitTest::Consturctor called\n";
}


UnitTest *UnitTest::GetAllInstance() 
{
    static UnitTest instance;
    return &instance;
}

int UnitTest::RegisterTest(Test* test)
{
    if (test)
        return impl()->Register(test);
    else 
        return 1;
}   

int UnitTest::RunAllTest()
{
    return impl()->Run();
}

UnitTestImpl::UnitTestImpl()
{
    tests_ = std::vector<Test*>();
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
    
    std::cout << "[==========] Running " << tests_.size() << " tests.\n";
    for (auto it = tests_.begin();
         it != tests_.end(); 
         it++)
    {
        Test *current_test = *it;
        current_test->TestBody();
    }
    
    return 0;
}

} // namespace testing
} // namespace lest
