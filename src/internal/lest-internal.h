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
    }; \
	lest::UnitTest::RegisterTest(test_group, test_name); \
    void LEST_CLASS_NAME(test_name, test_group)::TestBody()

namespace lest {
namespace testing {
class UnitTestImpl;

class TestResult {
public:
    bool passed;
    std::string message;
    std::chrono::milliseconds duration;

    TestResult(bool p = true, const std::string& msg = "", std::chrono::milliseconds dur = std::chrono::milliseconds(0))
        : passed(p), message(msg), duration(dur) {}
};

class UnitTest {
friend class UnitTestImpl;
public:
    int RegisterTest(Test* test) {
        return impl_->Register(test);
    }

	static UnitTestImpl *GetAllInstance() {
		return impl_;
	}	
    
    int RunAllTest()
    {
        return impl_->Run();
    }
public:
    UnitTest(const std::string& group, const std::string& name)
        : group_name(group), test_name(name) {
    }

    virtual ~UnitTest() = default;
	
    const std::string& GetGroupName() const { return group_name; }
    const std::string& GetTestName() const { return test_name; }

protected:
	static UnitTestImpl *impl_;
    std::string group_name;
    std::string test_name;
	/**
	 * the test is seperated into different groups
	 */
	std::unordered_map<std::string, std::vector<Test>> unit_tests_;
};

/**
 * the implementation for unit test.
 */
class UnitTestImpl {
friend class UnitTest;
public:
    int Register(Test* test) {
		tests_.push_back(test);
        return 0;
    }
    int Run()
    {
        std::cout << "Running test from " << __FILE__ << std::endl;
    }
public:
    UnitTestImpl() = default;
    std::vector<lest::testing::Test*> tests_;
};

} // namespace testing
} // namespace lest

#endif // LEST_INTERNAL_H
