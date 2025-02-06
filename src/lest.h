#include <iostream>

#include "internal/lest-internal.h"



#define LEST_TEST(test_group, test_name)                            \
    LEST_TEST_(test_group, test_name, lest::testing::Test)


#define TEST(test_group, test_name) LEST_TEST(test_group, test_name)

