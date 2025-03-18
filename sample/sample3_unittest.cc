#include "lest.h"

int foo(int n)
{
    return n + 1;
}

std::string add_(std::string s)
{
    return s + "_";
}

bool foo(bool t)
{
    return false;   
}

TEST(FooTest, pos)
{
    EQ(2, foo(1));
    EQ(3, foo(2));
}

TEST(FooTest, neg)
{
    GE(0, foo(-1));
    LE(0, foo(-1));
}

TEST(AddTest, basic)
{
    EQ(std::string("test_"), add_(std::string("test")));
    EQ(std::string("hello"), add_(std::string("hello")));
}

TEST(AddTest, empty)
{
    EQ(std::string("_"), add_(std::string("")));
}

TEST(AddTest, multiple)
{
    EQ(std::string("abc_def_"), add_(std::string("abc_def")));
}