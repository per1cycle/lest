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
    writer_ = xmlNewTextWriterFilename("test.xml", 0);
    xmlTextWriterStartDocument(writer_, NULL, "UTF-8", NULL);
    xmlTextWriterStartElement(writer_, reinterpret_cast<const unsigned char *>("Powersettings"));
}

Generator::Generator(const std::string& report_file)
: report_file_(report_file)
{
    writer_ = xmlNewTextWriterFilename(report_file_.c_str(), 0);
    xmlTextWriterStartDocument(writer_, NULL, "UTF-8", NULL);
    xmlTextWriterStartElement(writer_, reinterpret_cast<const unsigned char *>("Powersettings"));
}

Generator::~Generator()
{
    xmlTextWriterEndElement(writer_);
    xmlTextWriterEndDocument(writer_);
    xmlFreeTextWriter(writer_);
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

int Generator::GenerateSingleReport(lest::result::TestResult &result)
{
    xmlTextWriterWriteElement(writer_, 
        reinterpret_cast<const unsigned char *>("PowerScheme"),
        reinterpret_cast<const unsigned char *>("Testing"));
    xmlTextWriterEndElement(writer_);
    return 0;
}


}// namespace generator
} // namespace lest