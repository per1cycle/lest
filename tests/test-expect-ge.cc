#include "lest.h"

TEST(GETest, IntegersGreaterEqual)
{
    GE(0, 0);
    GE(1, 0);
    GE(INT_MAX, INT_MIN);
}

TEST(GETest, FloatingPointGreaterEqual)
{
    GE(2.0, 1.0);
    GE(-1.0, -2.0);
    GE(3.14, 3.14); // equality edge case
}

TEST(GETest, StringLexCompare)
{
    GE(std::string("zoo"), std::string("apple"));
    GE(std::string("equal"), std::string("equal"));
}
