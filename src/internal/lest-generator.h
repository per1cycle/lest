/**
 * lest report xml generator.
 */

#ifndef LEST_GENERATOR_H
#define LEST_GENERATOR_H

#include <libxml2/libxml/xmlwriter.h>

#include <chrono>   


#include <internal/lest-internal.h>
#include <internal/lest-result.h>

namespace lest
{
namespace generator
{
// generate xml report
class Generator
{
public:
    Generator();
    Generator(const std::string& report_file);
    ~Generator();

public:
    int GenerateReport(std::vector<lest::result::TestResult>& results, bool generate_passed);
    int GenerateFailedReport(std::vector<lest::result::TestResult>& results);
    int GeneratePassedReport(std::vector<lest::result::TestResult>& results);
    int GenerateSingleReport(lest::result::TestResult &result);
private:
    std::string report_file_;
    xmlTextWriterPtr writer_;
};

} // generator

} // lest

#endif // LEST_GENERATOR_H