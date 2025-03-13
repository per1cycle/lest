#ifndef LEST_INTERNAL_H
#define LEST_INTERNAL_H

#include <string>
#include <vector>
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
    protected: \
        void TestBody() override; \
        static Test * const test_; \
    }; \
    lest::testing::Test *const LEST_CLASS_NAME(test_name, test_group)::test_ = \
        lest::testing::UnitTest::GetAllInstance()->Register(new LEST_CLASS_NAME(test_name, test_group)); \
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
    Test* RegisterTest(Test* test);
	static UnitTestImpl *GetAllInstance();    
    int RunAllTest();
    static UnitTestImpl *impl();

public:
    UnitTest();

    virtual ~UnitTest() = default;
	
public:
    static bool debug_;
	static UnitTestImpl *impl_;
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
    Test* Register(Test* test);
    int Run();
    
public:
    UnitTestImpl();
    std::vector<lest::testing::Test*> tests_;
};

} // namespace testing
} // namespace lest

#endif // LEST_INTERNAL_H
