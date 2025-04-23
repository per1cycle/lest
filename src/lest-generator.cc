#include "internal/lest-generator.h"
#include <chrono>
#include <memory>

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

int Generator::GenerateReport(const std::vector<std::unique_ptr<lest::result::TestResult> >& results)
{
    // generate report
    // generate passed test report
    
    // debug
    std::vector<std::unique_ptr<lest::result::TestResult> > res;
    // res.push_back(std::make_unique<lest::result::TestResult>());
    GeneratePassedReport(res);
    // generate failed test report
    // GenerateFailedReport();
    return 0;
}

int Generator::GeneratePassedReport(const std::vector<std::unique_ptr<lest::result::TestResult> >& results)
{
    // generate passed test report
    for (const auto& result : results)
    {
        if (result)
        {
            // process passed test result
        }
    }
    return 0;
}

int Generator::GenerateFailedReport(const std::vector<std::unique_ptr<lest::result::TestResult> >& results)
{
    
    return 0;
}



}// namespace generator
} // namespace lest