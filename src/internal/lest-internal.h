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
    class LEST_CLASS_NAME(test_group, test_name): public parent_class { \
    public: \
        LEST_CLASS_NAME(test_group, test_name)() : Test(#test_group, #test_name) {} \
    public: \
        void TestBody() override; \
        static int const register_result_; \
    }; \
    int const LEST_CLASS_NAME(test_group, test_name)::register_result_ = \
        lest::testing::UnitTest::GetAllInstance()->RegisterTest(new LEST_CLASS_NAME(test_group, test_name)()); \
    void LEST_CLASS_NAME(test_group, test_name)::TestBody()
#define LEST_TEST_F_(test_fixture, test_name) \
    class LEST_CLASS_NAME(test_fixture, test_name): public test_fixture { \
    public: \
        LEST_CLASS_NAME(test_fixture, test_name)(): test_fixture(#test_fixture, #test_name) {} \
        void TestBody() override final { \
            Setup(); \
            try { \
                Body(); \
            } catch (...) { \
                TearDown(); \
                throw; \
            } \
            TearDown(); \
        } \
        void Body(); \
        static int const register_result_; \
    }; \
    int const LEST_CLASS_NAME(test_fixture, test_name)::register_result_ = \
        lest::testing::UnitTest::GetAllInstance()->RegisterTest(new LEST_CLASS_NAME(test_fixture, test_name)()); \
    void LEST_CLASS_NAME(test_fixture, test_name)::Body()


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
    int GenerateReport(bool generate_passed);
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
    int GenerateReport(bool generate_passed = false);
public:
    UnitTestImpl();
private:
    std::vector<Test*> tests_;
    std::set<Test*> failed_;
    std::set<lest::result::TestResult> results_;

};

} // namespace testing
} // namespace lest

#endif // LEST_INTERNAL_H
