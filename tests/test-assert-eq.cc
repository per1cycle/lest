#include "lest.h"
#include <string>

TEST(EQTest, IntegersEqual)
{
    AEQ(0, 0);               // boundary value
    AEQ(1, 1);               // positive
    AEQ(-1, -1);             // negative
    AEQ(INT_MAX, INT_MAX);   // max boundary
    AEQ(INT_MIN, INT_MIN);   // min boundary
}

TEST(EQTest, FloatingPointEqual)
{
    AEQ(0.0, 0.0);
    AEQ(1.5, 1.5);
    AEQ(0.3, 0.1 + 0.2);
    AEQ(-2.75, -2.75);
}

TEST(EQTest, StringsEqual)
{
    AEQ(std::string(""), std::string(""));     // empty string
    AEQ(std::string("lest"), std::string("lest"));
    AEQ(std::string("边界"), std::string("边界"));  // unicode
}

TEST(EQTest, CustomMessageWhenFails)
{
    int a = 1, b = 2;
    AEQ(a, b); // uncomment to trigger failure manually
}
