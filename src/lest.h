#ifndef LEST_H
#define LEST_H

#include "internal/lest-internal.h"
#include "internal/lest-testing.h"
#include "internal/lest-define.h"
#include "internal/lest-testing.h"

#include <iostream>

#define LEST_TEST(test_group, test_name)                            \
    LEST_TEST_(test_group, test_name, lest::testing::Test)

// every time call the TEST macro will register a unit test class
// and RUN will run all the registered unit test classes,
// test is separated by test_group and test_name.
#define TEST(test_group, test_name) LEST_TEST(test_group, test_name)

static int RUN() { lest::testing::UnitTest::GetInstance()->Run(); }



#endif // LEST_H