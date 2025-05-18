#include "lest.h"

TEST(LETest, IntegersLessEqual)
{
    ALE(0, 0);
    ALE(-1, 0);
    ALE(INT_MIN, INT_MIN);
    ALE(INT_MIN, INT_MAX);
}

TEST(LETest, Floats)
{
    ALE(1.5, 2.5);
    ALE(2.5, 2.5);
}

TEST(LETest, Strings)
{
    ALE(std::string("abc"), std::string("abc"));
    ALE(std::string("abc"), std::string("bcd"));
}
