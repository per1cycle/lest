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
    EQ(4, foo(3));
    EQ(5, foo(4));
    EQ(6, foo(5));
    EQ(100, foo(99));
    EQ(1000, foo(999));
    EQ(10, foo(9));
    EQ(20, foo(19));
    EQ(30, foo(29));
}

TEST(FooTest, neg)
{
    GE(0, foo(-1));
    LE(0, foo(-1));
    GE(0, foo(-10));
    LE(0, foo(-10));
    GE(0, foo(-100));
    LE(0, foo(-100));
    GE(0, foo(-50));
    LE(0, foo(-50));
    GE(0, foo(-5));
    LE(0, foo(-5));
}

TEST(AddTest, basic)
{
    EQ(std::string("test_"), add_(std::string("test")));
    EQ(std::string("hello_"), add_(std::string("hello")));
    EQ(std::string("world_"), add_(std::string("world")));
    EQ(std::string("foo_"), add_(std::string("foo")));
    EQ(std::string("bar_"), add_(std::string("bar")));
    EQ(std::string("baz_"), add_(std::string("baz")));
    EQ(std::string("example_"), add_(std::string("example")));
    EQ(std::string("test123_"), add_(std::string("test123")));
    EQ(std::string("abc_"), add_(std::string("abc")));
    EQ(std::string("xyz_"), add_(std::string("xyz")));
}

TEST(AddTest, empty)
{
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
    EQ(std::string("_"), add_(std::string("")));
}

TEST(AddTest, multiple)
{
    EQ(std::string("abc_def_"), add_(std::string("abc_def")));
    EQ(std::string("hello_world_"), add_(std::string("hello_world")));
    EQ(std::string("foo_bar_"), add_(std::string("foo_bar")));
    EQ(std::string("test_case_"), add_(std::string("test_case")));
    EQ(std::string("example_test_"), add_(std::string("example_test")));
    EQ(std::string("multiple_words_"), add_(std::string("multiple_words")));
    EQ(std::string("string_test_"), add_(std::string("string_test")));
    EQ(std::string("abc_xyz_"), add_(std::string("abc_xyz")));
    EQ(std::string("test_string_"), add_(std::string("test_string")));
    EQ(std::string("foo_baz_"), add_(std::string("foo_baz")));
}
/**
 * super long test....
 */
TEST(FooTest, edge_cases)
{
    EQ(1, foo(0));
    EQ(0, foo(-1));
    EQ(1, foo(-1));
    EQ(1001, foo(1000));
    EQ(1001, foo(1000));
    EQ(1001, foo(1000));
}