/**
 * lest report xml generator.
 */

#ifndef LEST_GENERATOR_H
#define LEST_GENERATOR_H

#include <libxml/xmlwriter.h>
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

public:
    int GenerateReport(std::vector<lest::result::TestResult> &results_);
    int GenerateFailedReport(std::vector<lest::result::TestResult> &results_);
    int GeneratePassedReport(std::vector<lest::result::TestResult> &results_);

private:
    std::string report_file_;

};

} // generator

} // lest

#endif // LEST_GENERATOR_H