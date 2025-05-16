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
    xmlTextWriterStartElement(writer_, reinterpret_cast<const unsigned char *>("Lest_report"));
}

Generator::~Generator()
{
    xmlTextWriterEndElement(writer_);
    xmlTextWriterEndDocument(writer_);
    xmlFreeTextWriter(writer_);
}

int Generator::GenerateReport(std::vector<lest::result::TestResult>& results, bool generate_passed)
{
    GenerateFailedReport(results);
    if(generate_passed)
        GeneratePassedReport(results);
    return 0;
}

int Generator::GeneratePassedReport(std::vector<lest::result::TestResult>& results)
{
    xmlTextWriterStartElement(writer_, 
        reinterpret_cast<const unsigned char*>("Passed_reports"));
    
    for(int i = 0; i < results.size(); i ++)
    {
        if(!results[i].is_passed())
            continue;
        GenerateSingleReport(results[i]);
    }
    xmlTextWriterEndElement(writer_);

    return 0;
}

int Generator::GenerateFailedReport(std::vector<lest::result::TestResult>& results)
{
    xmlTextWriterStartElement(writer_, 
        reinterpret_cast<const unsigned char*>("Failed_reports"));
    
    for(int i = 0; i < results.size(); i ++)
    {
        if(results[i].is_passed())
            continue;
        GenerateSingleReport(results[i]);
    }
    
    xmlTextWriterEndElement(writer_);
    return 0;
}

int Generator::GenerateSingleReport(lest::result::TestResult &result)
{

    xmlTextWriterWriteElement(writer_, 
        reinterpret_cast<const unsigned char *>("Test_result"),
        reinterpret_cast<const unsigned char *>(result.is_passed()? "Passed": "Failed"));
    // xmlTextWriterEndElement(writer_);

    xmlTextWriterWriteElement(writer_, 
        reinterpret_cast<const unsigned char *>("Test_group"),
        reinterpret_cast<const unsigned char *>(result.test_group().c_str()));
    // xmlTextWriterEndElement(writer_);

    xmlTextWriterWriteElement(writer_, 
        reinterpret_cast<const unsigned char *>("Test_name"),
        reinterpret_cast<const unsigned char *>(result.test_name().c_str()));
    // xmlTextWriterEndElement(writer_);
    return 0;
}


}// namespace generator
} // namespace lest