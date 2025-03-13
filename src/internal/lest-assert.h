#ifndef LEAST_ASSERT_H
#define LEAST_ASSERT_H

#include <string>
#include <stdexcept>
#include <sstream>

#include "internal/lest-define.h"
#include "internal/lest-compare.h"

#define LEST_ASSERT(CONDITION, expression1, expression2) \
    LEST_ASSERT_(CONDITION, expression1, expression2)

namespace lest {

/**
 * consider a better way to implement assert.
 */
// template <typename t1, typename t2>


} // namespace lest

#endif // LEAST_ASSERT_H
