/**
 * lest report xml generator.
 */

#ifndef LEST_GENERATOR_H
#define LEST_GENERATOR_H

#include <libxml/xmlwriter.h>
#include <chrono>   


#include <internal/lest-internal.h>

namespace lest
{
namespace generator
{
// generate xml report
class Generator
{
public:
    Generator();

public:
    int GenerateReport();
    int GenerateFailedReport(testing::);
    int GeneratePassedReport();

private:
    xmlTextWriterPtr writer_;    

};

} // generator

} // lest

#endif // LEST_GENERATOR_H