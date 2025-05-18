#include "lest.h"

TEST(NETest, IntegersNotEqual)
{
    NE(1, 0);
    NE(INT_MAX, INT_MIN);
    NE(-100, 100);
}

TEST(NETest, FloatingPointNotEqual)
{
    NE(1.0, 0.0);
    NE(-3.14, 3.14);
}

TEST(NETest, StringsNotEqual)
{
    NE(std::string("lest"), std::string("LEST"));
    NE(std::string(""), std::string("nonempty"));
    NE(std::string("a"), std::string("ä")); // boundary: ASCII vs Unicode
}
