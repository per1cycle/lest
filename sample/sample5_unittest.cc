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

private:
    int x_;

};

TEST(Foo, DefaultConstructor)
{
    Foo f_default;
    EQ(f_default.X(), 42);
}

TEST(Foo, ConstructorX)
{
    Foo f_x(100);
    NE(f_x.X(), 42);
    AEQ(f_x.X(), 42);
}
