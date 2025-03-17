#ifndef LEAST_ASSERT_H
#define LEAST_ASSERT_H

#include <string>
#include <stdexcept>
#include <sstream>

#include "internal/lest-define.h"
#include "internal/lest-compare.h"

#define LEST_ASSERT(CONDITION, expression1, expression2) \
    LEST_ASSERT_(CONDITION, expression1, expression2)

/**
 * use switch case for implement the comparasion
 */
#define LEST_ASSERT_(CONDITION, expression1, expression2) \
    switch (CONDITION) { \
        case lest::Compare::EQ: \
            if (!(expression1 == expression2)) { \
                std::ostringstream oss; \
                LOG_ERROR << "Test failed"; \
                oss << "Assertion failed: " << #expression1 << " == " << #expression2 << " (" << expression1 << " vs " << expression2 << ")"; \
                throw std::runtime_error(oss.str()); \
            } \
            break; \
    }

namespace lest {
namespace assert{
/**
 * consider a better way to implement assert.
 */
class AssertHelper
{
public:
    AssertHelper();
public:
    // thie function wrap a test body which does not let whole program crash even error.
    static int WrapRuntimeError();
    int TODO();
};

} // namespace assert
} // namespace lest

#endif // LEAST_ASSERT_H
