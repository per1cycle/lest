#include "internal/lest-generator.h"
#include <chrono>
#include <memory>
#include <iostream>

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

int Generator::GenerateReport(std::vector<lest::result::TestResult>& results, bool generate_passed)
{

    return 0;
}

int Generator::GeneratePassedReport(std::vector<lest::result::TestResult>& results)
{

    return 0;
}

int Generator::GenerateFailedReport(std::vector<lest::result::TestResult>& results)
{
    
    return 0;
}

int GenerateSingleReport(lest::result::TestResult &result)
{
    
}


}// namespace generator
} // namespace lest