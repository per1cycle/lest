#include <iostream>

#include "lest-assert.cc"
#include "lest-testing.cc"


#define LEST_TEST(test_group, test_name)    \
    static_assert(sizeof(test_group) > 1, "Name of test group shouldn't be empty."); \
    static_assert(sizeof(test_name) > 1, "Name of test case shouldn't be empty.");   \
    std::cout << "Begining test.\n";

#define TEST(test_group, test_name) LEST_TEST(test_group, test_name)

