#include <lest.h>
#include <iostream>
#define CLASS_NAME(x) #x
class Base
{
public:
    Base(int x): x_(x){}
private:
    int x_;

};

int main(int argc, char const *argv[])
{
    std::cout << LEST_VERSION << std::endl;    
    lest::generator::Generator generator(lest::utils::current_time() + ".xml");
    lest::result::TestResult result(true, "fun_group", "positive");
    generator.GenerateSingleReport(result);
    return 0;
}
