#ifndef LEST_INTERNAL_H
#define LEST_INTERNAL_H

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <chrono>

#define LEST_STRINGIFY_(test_name, test_group) test_group##_##test_name##_Test

#define LEST_TEST_(test_name, test_group) \
    class LEST_STRINGIFY_(test_name, test_group) : public lest::testing::Test { \
    public: \
        LEST_STRINGIFY_(test_name, test_group)() : Test(#test_group, #test_name) {} \
    protected: \
        void TestBody() override; \
    }; \
    static LEST_STRINGIFY_(test_name, test_group) LEST_STRINGIFY_(test_name, test_group); \
    void LEST_STRINGIFY_(test_name, test_group)::TestBody()
        


namespace lest {
namespace testing {

class TestResult {
public:
    bool passed;
    std::string message;
    std::chrono::milliseconds duration;

    TestResult(bool p = true, const std::string& msg = "", std::chrono::milliseconds dur = std::chrono::milliseconds(0))
        : passed(p), message(msg), duration(dur) {}
};

class UnitTest {
public:
    UnitTest(const std::string& group, const std::string& name)
        : group_name(group), test_name(name) {
        UnitTestImpl::GetInstance().RegisterTest(this);
    }

    virtual ~UnitTest() = default;
    void RunTest();

    const std::string& GetGroupName() const { return group_name; }
    const std::string& GetTestName() const { return test_name; }

protected:
    std::string group_name;
    std::string test_name;
};

class UnitTestImpl {
public:
    static UnitTestImpl& GetInstance() {
        static UnitTestImpl instance;
        return instance;
    }

    void RegisterTest(UnitTest* test) {
        tests.push_back(test);
    }

    int RunAllTests() {
        int failed = 0;
        std::cout << "\nRunning " << tests.size() << " tests...\n\n";

        for (UnitTest* test : tests) {
            try {
                auto start = std::chrono::high_resolution_clock::now();
                
                std::cout << "[ RUN    ] " << test->GetGroupName() 
                         << "::" << test->GetTestName() << "\n";
                
                test->RunTest();
                
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                
                std::cout << "[ PASSED ] (" << duration.count() << "ms)\n";
            }
            catch (const std::exception& e) {
                failed++;
                std::cout << "[ FAILED ] " << e.what() << "\n";
            }
        }

        std::cout << "\nTest results: "
                  << (tests.size() - failed) << " passed, "
                  << failed << " failed\n";

        return failed;
    }

private:
    UnitTestImpl() = default;
    std::vector<UnitTest*> tests;
};

} // namespace testing
} // namespace lest

#define TEST(test_group, test_name) \
    LEST_TEST_(test_name, test_group)

#endif // LEST_INTERNAL_H