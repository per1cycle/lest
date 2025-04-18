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

int Generator::GenerateReport()
{
    // generate report
    // generate passed test report
    GeneratePassedReport();
    // generate failed test report
    GenerateFailedReport();
    return 0;
}

int Generator::GeneratePassedReport()
{
    // generate passed test report
    return 0;

}

int Generator::GenerateFailedReport()
{
    // generate failed test report
    return 0;
}

}// namespace generator
} // namespace lest