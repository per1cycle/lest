#include "lest.h"

TEST(NETest, IntegersNotEqual)
{
    ANE(1, 0);
    ANE(INT_MAX, INT_MIN);
    ANE(-100, 100);
}

TEST(NETest, FloatingPointNotEqual)
{
    ANE(1.0, 0.0);
    ANE(-3.14, 3.14);
}

TEST(NETest, StringsNotEqual)
{
    ANE(std::string("lest"), std::string("LEST"));
    ANE(std::string(""), std::string("nonempty"));
    ANE(std::string("a"), std::string("ä")); // boundary: ASCII vs Unicode
}
