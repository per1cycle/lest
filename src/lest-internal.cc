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

int UnitTest::AddFailedTest(Test* failed_test)
{
    return impl()->AddFailedTest(failed_test);
}

int UnitTest::HasFailedTest()
{
    return impl()->HasFailedTest();
}

UnitTestImpl::UnitTestImpl()
{
    tests_ = std::vector<Test*>();
}

int UnitTestImpl::Register(Test* test)
{
    tests_.push_back(test);
    return 0;
}

int UnitTestImpl::Run()
{
    int success_count = 0;
    int failed_count = 0;
    int skip_count = 0;
    
    LOG_INFO << "[==========] Running " << tests_.size() << " tests.";

    /**
     * Todo: add exception handler for running the test.
     */
    for (auto it = tests_.begin();
         it != tests_.end(); 
         it++)
    {
        Test *current_test = *it;
        LOG_INFO << "Running Test: #" << it - tests_.begin() + 1 << ": " << current_test->TestName();
        current_test->TestBody();
        LOG_INFO << "Test #" << it - tests_.begin() << " Finished.";
    }

    if (1)
    {
        LOG_WARNING << "Has " << HasFailedTest() << " failed tests.";
    } else 
    {
        LOG_INFO << "[==========] Finish running " << tests_.size() << " tests, No error.\n";
    }
    return 0;
}

int UnitTestImpl::AddFailedTest(Test* fail_test)
{
    failed_.push_back(fail_test);
    return 1;
}

int UnitTestImpl::HasFailedTest()
{
    return failed_.size();
}

} // namespace testing
} // namespace lest
