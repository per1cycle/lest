#ifndef LEST_H
#define LEST_H

#include "internal/lest-internal.h"
#include "internal/lest-testing.h"
#include "internal/lest-define.h"
#include "internal/lest-testing.h"

#include <iostream>

// every time call the TEST macro will register a unit test class
// and RUN will run all the registered unit test classes,
// test is separated by test_group and test_name.
#define TEST(test_group, test_name) LEST_TEST(test_group, test_name)

#define LEST_TEST(test_group, test_name)                            \
    LEST_TEST_(test_group, test_name, lest::testing::Test)


static int RUN() { return 0; }



#endif // LEST_H