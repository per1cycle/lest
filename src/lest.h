#ifndef LEST_H
#define LEST_H

#define LEST_VERSION_MAJOR "0"
#define LEST_VERSION_MINOR "1"
#define LEST_STRINGIFY_VERSION(major, minor) major "." minor
#define LEST_VERSION LEST_STRINGIFY_VERSION(LEST_VERSION_MAJOR, LEST_VERSION_MINOR)

#include "internal/lest-internal.h"
#include <iostream>

#define LEST_TEST(test_group, test_name)                            \
    LEST_TEST_(test_group, test_name, lest::testing::Test)

#define TEST(test_group, test_name) LEST_TEST(test_group, test_name)

#endif // LEST_H