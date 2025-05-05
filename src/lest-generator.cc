#include "internal/lest-generator.h"
#include <chrono>
#include <memory>
#include <iostream>

#include <libxml/xmlwriter.h>

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
    writer_ = xmlNewTextWriterFilename(report_file_.c_str(), 0);
    xmlTextWriterStartDocument(writer_, NULL, "UTF-8", NULL);
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
    xmlTextWriterWriteElement(writer_, "PowerScheme", "Testing")
}


}// namespace generator
} // namespace lest