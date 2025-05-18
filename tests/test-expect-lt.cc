#include "lest.h"

TEST(LTTest, IntegersLessThan)
{
    LT(-1, 0);
    LT(0, 1);
    LT(INT_MIN, 0);
    LT(INT_MIN, INT_MAX); // large range
}

TEST(LTTest, FloatingPointLessThan)
{
    LT(-2.0, -1.0);
    LT(0.1, 1.0);
    LT(-1.5, 0.0);
}

TEST(LTTest, NegativeCases)
{
    // test where condition would fail
    int x = 2, y = 1;
    if (!(x < y)) std::cerr << "Expected x < y to fail\n";
    // LT(x, y); // Uncomment for failure test
}
