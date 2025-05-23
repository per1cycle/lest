#include "internal/lest-internal.h"
#include "internal/lest-define.h"
#include "internal/lest-generator.h"
#include "internal/lest-utils.h"
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

int UnitTest::GenerateReport(bool generate_passed)
{
    return impl()->GenerateReport(generate_passed);
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
        lest::utils::Timer local_timer;
        local_timer.start();
        current_test->TestBody();
        local_timer.stop();
        LOG_INFO << "Test #" << it - tests_.begin() << " Finished. Cost: " << local_timer.elapse_in_second() << "s.";
    }

    if (HasFailedTest())
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
    failed_.insert(fail_test);
    return 1;
}

int UnitTestImpl::HasFailedTest()
{
    return failed_.size();
}

int UnitTestImpl::GenerateReport(bool generated_passed)
{
    lest::generator::Generator g(lest::utils::current_time() + ".xml");
    std::vector<lest::result::TestResult> results;
    // start generated report vector
    for(int i = 0; i < tests_.size(); i ++)
    {
        std::set<Test*>::iterator f;
        if(!failed_.size())
        {
            continue;
        }
        for(f = failed_.begin(); f != failed_.end(); f ++)
        {
            if(tests_[i]->test_group_ == (*f)->test_group_ && tests_[i]->test_name_ == (*f)->test_name_)
            {
                lest::result::TestResult res(false, (*f)->test_group_, (*f)->test_name_);
                results.push_back(res);
                break;
            }
        }
        if(f == failed_.end()) // didn't find failed test
        {
            lest::result::TestResult res(true, tests_[i]->test_group_, tests_[i]->test_name_);
            results.push_back(res);
        }
    }
    LOG << "Total report results: " << results.size();
    return g.GenerateReport(results, generated_passed);
    // return 1;
}

} // namespace testing
} // namespace lest
