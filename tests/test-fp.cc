#include <lest.h>

TEST(Float, good)
{
    EQ(0.3, 0.1 + 0.2);
    EQ(0.3, 0.10001 + 0.2);
}

TEST(Float, bad)
{
    EQ(0.1, 0.100001);
    EQ(0.1f, 0.1f + 1e-10);
}