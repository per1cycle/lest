#ifndef LEST_INTERNAL_H
#define LEST_INTERNAL_H

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <chrono>

#include "internal/lest-define.h"

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
	\
    void LEST_CLASS_NAME(test_name, test_group)::TestBody()

namespace lest {
namespace testing {
class UnitTestImpl;

class LEST_API UnitTest {
public:
    static UnitTest* GetAllInstance();
public:
    UnitTest();
    UnitTest(const std::string& group, const std::string& name);
    virtual ~UnitTest() = default;
    UnitTestImpl *impl();
    int Run();
protected:
	UnitTestImpl *impl_;
};

/**
 * the implementation for unit test.
 * this class can:
 * - register a test
 * - run all tests
 */
class LEST_API UnitTestImpl {
public:
    void RegisterTest();
private:
    UnitTestImpl() = default;
};

} // namespace testing
} // namespace lest

#endif // LEST_INTERNAL_H
