#include <lest.h>

int foo(int n)
{
    return n + 1;
}

TEST(foo, pos)
{
    EQ(2, foo(1));
    EQ(2001, foo(2000));
}

TEST(foo, neg)
{
    EQ(0, foo(-1));
    GT(foo(-3), -3);
    LT(-3, foo(-3));
}

TEST(foo, negfail1)
{
    for(int i = 0; i < 100; i ++)
    {
        GT(foo(-3), -3);
    }
    GT(foo(-3), 3);
    LT(-3, foo(-3));
}
