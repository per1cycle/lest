#ifndef LEAST_ASSERT_H
#define LEAST_ASSERT_H

#include <string>
#include <stdexcept>
#include <sstream>

#include "internal/lest-define.h"
#include "internal/lest-compare.h"

#define LEST_ASSERT(CONDITION, expression1, expression2) \
    LEST_ASSERT_(CONDITION, expression1, expression2)

#define LEST_ASSERT_(CONDITION, expression1, expression2) \
    if (!(CONDITION(expression1, expression2))) { \
        std::ostringstream oss; \
        oss << "Assertion failed: " << #expression1 << " " << #CONDITION << " " << #expression2; \
        throw std::runtime_error(oss.str()); \
    }
namespace lest {

/**
 * consider a better way to implement assert.
 */

} // namespace lest

#endif // LEAST_ASSERT_H
