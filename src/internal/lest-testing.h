#ifndef LEAST_TESTING_H
#define LEAST_TESTING_H

#include <string>
#include "internal/lest-define.h"

namespace lest {
namespace testing {

class UnitTest;
class TestInfo;

class Test {
public:
    Test(const std::string& test_group, const std::string& test_name) 
        : group_name_(test_group), test_name_(test_name) { }

    virtual ~Test() = default;

    // Get test information
    const std::string& GetTestName() const { return test_name_; }
    const std::string& GetGroupName() const { return group_name_; }

    // Run the test
    void Run() {
        TestBody();
    }
	
	TestInfo *MakeAndRegister(std::string test_group, test_name)
	{
		
	}
protected:
    virtual void TestBody() = 0;

private:

    std::string group_name_;
    std::string test_name_;
};

} // namespace testing
} // namespace lest

#endif // LEAST_TESTING_H
