#ifndef LEST_INTERNAL_H
#define LEST_INTERNAL_H

#include <string>
#include <vector>
#include <set>
#include <functional>
#include <iostream>
#include <chrono>

#include "internal/lest-define.h"
#include "internal/lest-testing.h"

#define LEST_CLASS_NAME(test_group, test_name) test_group##_##test_name##_Test

/**
 * This macro automatically register the current test to UnitTest.
 */
#define LEST_TEST_(test_name, test_group, parent_class) \
    class LEST_CLASS_NAME(test_name, test_group): public parent_class { \
    public: \
        LEST_CLASS_NAME(test_name, test_group)() : Test(#test_group, #test_name) {} \
    public: \
        void TestBody() override; \
        static int const register_result_; \
    }; \
    int const LEST_CLASS_NAME(test_name, test_group)::register_result_ = \
        lest::testing::UnitTest::GetAllInstance()->RegisterTest(new LEST_CLASS_NAME(test_name, test_group)()); \
    void LEST_CLASS_NAME(test_name, test_group)::TestBody()

namespace lest {
namespace testing {
class UnitTestImpl;

class TestResult {
public:
    bool passed;
    std::string message;
    std::chrono::milliseconds duration;

    TestResult(bool p = true, const std::string& msg = "", std::chrono::milliseconds dur = std::chrono::milliseconds(0));
};

class UnitTest {
friend class UnitTestImpl;
public:
	static UnitTest *GetAllInstance();    
    int RunAllTest();
    int RegisterTest(Test* test);
    UnitTestImpl *impl();
    int AddFailedTest(Test* fail_test);
    int HasFailedTest();
public:
    UnitTest();

    virtual ~UnitTest() = default;
	
public:
	UnitTestImpl *impl_;
	/**
	 * the test is seperated into different groups
	 */
};

/**
 * the implementation for unit test.
 */
class UnitTestImpl {
friend class UnitTest;
public:
    // FIXME: when register a test should return test info
    // instead of Test.
    int Register(Test* test);
    int Run();
    int AddFailedTest(Test* fail_test);
    int HasFailedTest();
     
public:
    UnitTestImpl();
    std::vector<Test*> tests_;
    std::set<Test*> failed_;
};

} // namespace testing
} // namespace lest

#endif // LEST_INTERNAL_H
