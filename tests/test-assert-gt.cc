#include "lest.h"

TEST(GTTest, IntegersGreaterThan)
{
    AGT(1, 0);
    AGT(0, -1);
    AGT(INT_MAX, INT_MIN);
}

TEST(GTTest, FloatingPointGreaterThan)
{
    AGT(2.5, 1.5);
    AGT(0.1, -1.0);
}

TEST(GTTest, UnicodeStringComparison)
{
    std::string s1 = "café";
    std::string s2 = "caff";
    AGT(s2, s1); // fails lexically
}
