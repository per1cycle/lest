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
            lest::Compare::Eq
            break; \
    }

namespace lest {

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

} // namespace lest

#endif // LEAST_ASSERT_H
