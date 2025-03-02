#ifndef LEST_INTERNAL_H
#define LEST_INTERNAL_H

#define LEST_STRINGIFY_(test_name, test_group) test_group##_##test_name##_Test 
#define LEST_TEST_(test_name, test_group)           \
    std::cout << "Running test: " << #test_group << "::" << #test_name << std::endl;
        
namespace lest
{
namespace testing
{
class UnitTestImpl
{


};


};


};

#endif // LEST_INTERNAL_H