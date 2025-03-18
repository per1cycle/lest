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
    EQ(2, foo(-1));
    GT(foo(-3), 3);
    LT(-3, foo(-3));
}

TEST(foo, negfail2)
{
    EQ(2, foo(1));
    GT(foo(3), 3);
    LT(1000, foo(-3));
}