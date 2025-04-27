#ifndef LEAST_ASSERT_H
#define LEAST_ASSERT_H

#include <string>
#include <stdexcept>
#include <sstream>

#include "internal/lest-define.h"
#include "internal/lest-compare.h"

#define LEST_EXPECT(CONDITION, expression1, expression2) \
    LEST_EXPECT_(CONDITION, expression1, expression2) 

#define LEST_ASSERT(CONDITION, expression1, expression2) \
    LEST_ASSERT_(CONDITION, expression1, expression2)

/**
 * expect two condition,
 * register to unittest fail if expect fail.
 */
#define LEST_EXPECT_(CONDITION, expression1, expression2) \
    switch (CONDITION) { \
        case lest::Compare::EQ: \
            lest::Compare::EQImpl(expression1, expression2, this, false); \
            break; \
        case lest::Compare::NE: \
            lest::Compare::NEImpl(expression1, expression2, this, false); \
            break; \
        case lest::Compare::GT: \
            lest::Compare::GTImpl(expression1, expression2, this, false); \
            break; \
        case lest::Compare::GE: \
            lest::Compare::GEImpl(expression1, expression2, this, false); \
            break; \
        case lest::Compare::LT: \
            lest::Compare::LTImpl(expression1, expression2, this, false); \
            break; \
        case lest::Compare::LE: \
            lest::Compare::LEImpl(expression1, expression2, this, false); \
            break; \
        case lest::Compare::CMP: \
            lest::Compare::LEImpl(expression1, expression2, this, false); \
            break; \
    }


/**
 * use switch case for implement the comparasion
 */
#define LEST_ASSERT_(CONDITION, expression1, expression2) \
    switch (CONDITION) { \
        case lest::Compare::EQ: \
            if (expression1 == expression2) { \
                LOG_INFO << "TEST PASSED"; \
            } else {\
                std::ostringstream oss; \
                LOG_ERROR << "Test failed"; \
                oss << "Assertion failed: " << #expression1 << " == " << #expression2 << " (" << expression1 << " vs " << expression2 << ")"; \
                throw std::runtime_error(oss.str()); \
            } \
            break; \
        case lest::Compare::NE: \
            if (expression1 != expression2) { \
                LOG_INFO << "TEST PASSED"; \
            } else {\
                std::ostringstream oss; \
                LOG_ERROR << "Test failed"; \
                oss << "Assertion failed: " << #expression1 << " == " << #expression2 << " (" << expression1 << " vs " << expression2 << ")"; \
                throw std::runtime_error(oss.str()); \
            } \
            break; \
        case lest::Compare::GT: \
            if (expression1 > expression2) { \
                LOG_INFO << "TEST PASSED"; \
            } else {\
                std::ostringstream oss; \
                LOG_ERROR << "Test failed"; \
                oss << "Assertion failed: " << #expression1 << " == " << #expression2 << " (" << expression1 << " vs " << expression2 << ")"; \
                throw std::runtime_error(oss.str()); \
            } \
            break; \
        case lest::Compare::GE: \
            if (expression1 >= expression2) { \
                LOG_INFO << "TEST PASSED"; \
            } else {\
                std::ostringstream oss; \
                LOG_ERROR << "Test failed"; \
                oss << "Assertion failed: " << #expression1 << " == " << #expression2 << " (" << expression1 << " vs " << expression2 << ")"; \
                throw std::runtime_error(oss.str()); \
            } \
            break; \
        case lest::Compare::LT: \
            if (expression1 < expression2) { \
                LOG_INFO << "TEST PASSED"; \
            } else {\
                std::ostringstream oss; \
                LOG_ERROR << "Test failed"; \
                oss << "Assertion failed: " << #expression1 << " == " << #expression2 << " (" << expression1 << " vs " << expression2 << ")"; \
                throw std::runtime_error(oss.str()); \
            } \
            break; \
        case lest::Compare::LE: \
            if (expression1 <= expression2) { \
                LOG_INFO << "TEST PASSED"; \
            } else {\
                std::ostringstream oss; \
                LOG_ERROR << "Test failed"; \
                oss << "Assertion failed: " << #expression1 << " == " << #expression2 << " (" << expression1 << " vs " << expression2 << ")"; \
                throw std::runtime_error(oss.str()); \
            } \
            break; \
        case lest::Compare::CMP: \
            if (expression1 != expression2) { \
                LOG_INFO << "TEST PASSED"; \
            } else {\
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
