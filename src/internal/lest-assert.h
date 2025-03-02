#ifndef LEAST_ASSERT_H
#define LEAST_ASSERT_H

#include <string>
#include <stdexcept>
#include <sstream>

#include "internal/lest-define.h"

#define EXPECT_EQ(expected, actual) lest::Assert::AreEqual(expected, actual)

namespace lest {
/**
 * consider a better way to implement assert.
 */
// template <typename t1, typename t2>

} // namespace lest

#endif // LEAST_ASSERT_H