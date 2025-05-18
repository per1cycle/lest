#include "lest.h"

TEST(LTTest, IntegersLessThan)
{
    ALT(-1, 0);
    ALT(0, 1);
    ALT(INT_MIN, 0);
    ALT(INT_MIN, INT_MAX); // large range
}

TEST(LTTest, FloatingPointLessThan)
{
    ALT(-2.0, -1.0);
    ALT(0.1, 1.0);
    ALT(-1.5, 0.0);
}

TEST(LTTest, NegativeCases)
{
    // test where condition would fail
    int x = 2, y = 1;
    // ALT(x, y); // Uncomment for failure test
}
