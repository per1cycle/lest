#include <lest.h>
#include <iostream>
#define CLASS_NAME(x) #x
class Foo
{
public:
    Foo() {}

public:
    int foo()
    {
        std::cout << typeid(this).name() << " " << __func__ << std::endl;
        return 0;
    }
};

class Bar
{
public:
Bar()
{

}
private:
int bar1_;
std::string bar2_;

};

int main(int argc, char const *argv[])
{
    std::cout << LEST_VERSION << std::endl;    
    Foo f;
    f.foo(); 

    lest::generator::Generator gen;
    
    return 0;
}
