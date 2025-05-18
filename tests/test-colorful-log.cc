#include <lest.h>

TEST(Colorful, green)
{
    LOG_INFO << "This is green.";
}


TEST(Colorful, yellow)
{
    LOG_WARNING << "This is green.";
}


TEST(Colorful, red)
{
    LOG_ERROR << "This is green.";
}

