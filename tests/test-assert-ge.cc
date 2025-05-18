#include "lest.h"

TEST(GETest, IntegersGreaterEqual)
{
    AGE(0, 0);
    AGE(1, 0);
    AGE(INT_MAX, INT_MIN);
}

TEST(GETest, FloatingPointGreaterEqual)
{
    AGE(2.0, 1.0);
    AGE(-1.0, -2.0);
    AGE(3.14, 3.14); // equality edge case
}

TEST(GETest, StringLexCompare)
{
    AGE(std::string("zoo"), std::string("apple"));
    AGE(std::string("equal"), std::string("equal"));
}
