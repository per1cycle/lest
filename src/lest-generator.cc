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

int Generator::GenerateReport(const std::vector<std::unique_ptr<lest::result::TestResult> >& results, bool generate_passed)
{
    GenerateFailedReport(results);

    if(generate_passed)
        GeneratePassedReport(results);

    return 0;
}

int Generator::GeneratePassedReport(const std::vector<std::unique_ptr<lest::result::TestResult> >& results)
{

    return 0;
}

int Generator::GenerateFailedReport(const std::vector<std::unique_ptr<lest::result::TestResult> >& results)
{
    
    return 0;
}



}// namespace generator
} // namespace lest