#include "internal/lest-generator.h"
#include <chrono>

namespace lest
{
namespace generator
{
Generator::Generator()
{
    // generate current timestamp into a string

}

Generator::Generator(const std::string& report_file)
: report_file_(report_file)
{
}

int Generator::GenerateReport(std::vector<lest::result::TestResult> &results_)
{
    // generate report
    // generate passed test report
    GeneratePassedReport();
    // generate failed test report
    GenerateFailedReport();
    return 0;
}

int Generator::GeneratePassedReport(const std::vector<lest::testing::TestResult>& results)
{
    // generate passed test report
    for (const auto& result : results)
    {
        if (result.status == lest::testing::TestResult::PASSED)
        {
            // process passed test result
        }
    }
    return 0;
}
{
    // generate passed test report
    return 0;

}

int Generator::GenerateFailedReport(std::vector<lest::result::TestResult> &results_)
{
    
    return 0;
}



}// namespace generator
} // namespace lest