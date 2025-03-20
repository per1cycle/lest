/**
 * live demo for write test issue.
 */
#include <lest.h>

class Foo 
{
public:

Foo() 
{ 
    // default constructor set x to 42
    x_ = 42;
}

Foo(int x)
: x_(x)
{
    // Foo(x) set x_ = x
}

int X()
{
    return x_;
}

bool True()
{
    return true;
}

bool False()
{
    return false;
}

private:
    int x_;

};

