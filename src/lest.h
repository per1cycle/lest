#ifndef LEST_H
#define LEST_H

#include "internal/lest-internal.h"
#include "internal/lest-testing.h"
#include "internal/lest-define.h"
#include "internal/lest-testing.h"

#include <iostream>

#define LEST_TEST(test_group, test_name)                            \
    LEST_TEST_(test_group, test_name, lest::testing::Test)

#define TEST(test_group, test_name) LEST_TEST(test_group, test_name)


static int RUN() {}
#endif // LEST_H