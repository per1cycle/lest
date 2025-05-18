#include "lest.h"

TEST(GTTest, IntegersGreaterThan)
{
    GT(1, 0);
    GT(0, -1);
    GT(INT_MAX, INT_MIN);
}

TEST(GTTest, FloatingPointGreaterThan)
{
    GT(2.5, 1.5);
    GT(0.1, -1.0);
}

TEST(GTTest, UnicodeStringComparison)
{
    std::string s1 = "café";
    std::string s2 = "caff";
    GT(s2, s1); // fails lexically
}
