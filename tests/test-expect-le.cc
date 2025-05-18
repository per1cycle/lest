#include "lest.h"

TEST(LETest, IntegersLessEqual)
{
    LE(0, 0);
    LE(-1, 0);
    LE(INT_MIN, INT_MIN);
    LE(INT_MIN, INT_MAX);
}

TEST(LETest, Floats)
{
    LE(1.5, 2.5);
    LE(2.5, 2.5);
}

TEST(LETest, Strings)
{
    LE(std::string("abc"), std::string("abc"));
    LE(std::string("abc"), std::string("bcd"));
}
