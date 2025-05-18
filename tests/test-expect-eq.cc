#include "lest.h"
#include <string>

TEST(EQTest, IntegersEqual)
{
    EQ(0, 0);               // boundary value
    EQ(1, 1);               // positive
    EQ(-1, -1);             // negative
    EQ(INT_MAX, INT_MAX);   // max boundary
    EQ(INT_MIN, INT_MIN);   // min boundary
}

TEST(EQTest, FloatingPointEqual)
{
    EQ(0.0, 0.0);
    EQ(1.5, 1.5);
    EQ(0.3, 0.1 + 0.2);
    EQ(-2.75, -2.75);
}

TEST(EQTest, StringsEqual)
{
    EQ(std::string(""), std::string(""));     // empty string
    EQ(std::string("lest"), std::string("lest"));
    EQ(std::string("边界"), std::string("边界"));  // unicode
}

TEST(EQTest, CustomMessageWhenFails)
{
    int a = 1, b = 2;
    EQ(a, b); // uncomment to trigger failure manually
}
