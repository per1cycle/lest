#ifndef LEAST_TESTING_H
#define LEAST_TESTING_H

#include <string>
#include "lest-internal.h"

namespace lest {
namespace testing {

class Test {
public:
    Test(const std::string& test_group, const std::string& test_name) 
        : group_name_(test_group), test_name_(test_name) {
        RegisterTest();
    }

    virtual ~Test() = default;

    // Get test information
    const std::string& GetTestName() const { return test_name_; }
    const std::string& GetGroupName() const { return group_name_; }

    // Run the test
    void Run() {
        TestBody();
    }

protected:
    virtual void TestBody() = 0;

private:
    void RegisterTest() {
        
    }

    std::string group_name_;
    std::string test_name_;
};

} // namespace testing
} // namespace lest

#endif // LEAST_TESTING_H