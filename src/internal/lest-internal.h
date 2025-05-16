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
#include "internal/lest-result.h"

#define LEST_CLASS_NAME(test_group, test_name) test_group##_##test_name##_Test

/**
 * This macro automatically register the current test to UnitTest.
 */
#define LEST_TEST_(test_group, test_name, parent_class) \
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

#define LEST_TEST_F_(test_fixture, test_name) \
    class LEST_CLASS_NAME(test_fixture, test_name): public test_fixture { \
    public: \
        LEST_CLASS_NAME(test_fixture, test_name)(): test_fixture() { Setup(); } \
        ~LEST_CLASS_NAME(test_fixture, test_name)() { TearDown();} \
    public: \
        void TestBody() override; \
        static int const register_result_; \
    }; \
    int const LEST_CLASS_NAME(test_fixture, test_name)::register_result_ = \
        lest::testing::UnitTest::GetAllInstance()->RegisterTest(new LEST_CLASS_NAME(test_fixture, test_name)()); \
    void LEST_CLASS_NAME(test_fixture, test_name)::TestBody()

namespace lest {
namespace testing {
class UnitTestImpl;

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
	
private:
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
private:
    std::vector<Test*> tests_;
    std::set<Test*> failed_;
    std::vector<lest::result::TestResult> results_;

};

} // namespace testing
} // namespace lest

#endif // LEST_INTERNAL_H
