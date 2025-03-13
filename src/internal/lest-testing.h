#ifndef LEAST_TESTING_H
#define LEAST_TESTING_H

#include <string>
#include "internal/lest-define.h"

namespace lest {
namespace testing {

class UnitTest;
class TestInfo;
/**
 * Each time call TEST() macro will regiest a test to UnitTest.
 */
class Test {
friend class TestInfo;

public:
    Test();
    Test(const std::string& test_group, const std::string& test_name);

    virtual ~Test() = default;

public:
    virtual void TestBody() = 0;

};

/**
 * @brief The TestInfo class
 * This class is used to store the information of a test
 */
class LEST_API TestInfo
{
public:
    TestInfo();
private:
    const std::string test_group_name_;
    const std::string test_name_;

};

} // namespace testing
} // namespace lest

#endif // LEAST_TESTING_H
