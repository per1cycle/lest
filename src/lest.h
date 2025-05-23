#ifndef LEST_H
#define LEST_H

/**
 * during the development 2025/03/07
 * i think most of the definition should be moved here.
 */

#include "internal/lest-assert.h"
#include "internal/lest-compare.h"
#include "internal/lest-define.h"
#include "internal/lest-generator.h"
#include "internal/lest-internal.h"
#include "internal/lest-testing.h"
#include "internal/lest-utils.h"
// every time call the TEST macro will register a unit test class
// and RUN will run all the registered unit test classes,
// test is separated by test_group and test_name.
#define TEST(test_group, test_name) LEST_TEST(test_group, test_name)
#define TEST_F(test_fixture, test_name) LEST_TEST_F(test_fixture, test_name)

#define LEST_TEST(test_group, test_name) \
    LEST_TEST_(test_group, test_name, lest::testing::Test)

#define LEST_TEST_F(test_fixture, test_name) \
    LEST_TEST_F_(test_fixture, test_name)

/**
 * assertation for different expressions,
 * theres
 * - EQ =
 * - NE !=
 * - GT >
 * - GE >=
 * - LT <
 * - LE <=
 * - CMP user can design their own compare condition, need pass compare class;
 */

#define EQ(expression1, expression2) \
    LEST_EXPECT(lest::Compare::EQ, expression1, expression2)

#define TRUE(expression1) \
    LEST_EXPECT(lest::Compare::EQ, expression1, true)

#define FALSE(expression1) \
    LEST_EXPECT(lest::Compare::EQ, expression1, false)

#define NE(expression1, expression2) \
    LEST_EXPECT(lest::Compare::NE, expression1, expression2)

#define GE(expression1, expression2) \
    LEST_EXPECT(lest::Compare::GE, expression1, expression2)

#define GT(expression1, expression2) \
    LEST_EXPECT(lest::Compare::GT, expression1, expression2)

#define LE(expression1, expression2) \
    LEST_EXPECT(lest::Compare::LE, expression1, expression2)

#define LT(expression1, expression2) \
    LEST_EXPECT(lest::Compare::LT, expression1, expression2)

#define CMP_EQ(expression1, expression2, cmp_class) \
    LEST_EXPECT_CUSTOM_CMP(lest::Compare::CMP, expression1, expression2, cmp_class)

#define CMP_NE(expression1, expression2, cmp_class) \
    LEST_EXPECT_CUSTOM_CMP(lest::Compare::CMP, expression1, expression2, cmp_class)

#define CMP_GT(expression1, expression2, cmp_class) \
    LEST_EXPECT_CUSTOM_CMP(lest::Compare::CMP, expression1, expression2, cmp_class)

#define CMP_GE(expression1, expression2, cmp_class) \
    LEST_EXPECT_CUSTOM_CMP(lest::Compare::CMP, expression1, expression2, cmp_class)

#define CMP_LT(expression1, expression2, cmp_class) \
    LEST_EXPECT_CUSTOM_CMP(lest::Compare::CMP, expression1, expression2, cmp_class)

#define CMP_LE(expression1, expression2, cmp_class) \
    LEST_EXPECT_CUSTOM_CMP(lest::Compare::CMP, expression1, expression2, cmp_class)

#define AEQ(expression1, expression2) \
    LEST_ASSERT(lest::Compare::EQ, expression1, expression2)

#define ATRUE(expression1) \
    LEST_ASSERT(lest::Compare::EQ, expression1, true)

#define AFALSE(expression1) \
    LEST_ASSERT(lest::Compare::EQ, expression1, false)

#define ANE(expression1, expression2) \
    LEST_ASSERT(lest::Compare::NE, expression1, expression2)

#define AGE(expression1, expression2) \
    LEST_ASSERT(lest::Compare::GE, expression1, expression2)

#define AGT(expression1, expression2) \
    LEST_ASSERT(lest::Compare::GT, expression1, expression2)

#define ALE(expression1, expression2) \
    LEST_ASSERT(lest::Compare::LE, expression1, expression2)

#define ALT(expression1, expression2) \
    LEST_ASSERT(lest::Compare::LT, expression1, expression2)

#define ACMP_EQ(expression1, expression2, cmp_class) \
    LEST_ASSERT_CUSTOM_CMP(lest::Compare::EQ, expression1, expression2, cmp_class)

#define ACMP_NE(expression1, expression2, cmp_class) \
    LEST_ASSERT_CUSTOM_CMP(lest::Compare::NE, expression1, expression2, cmp_class)

#define ACMP_GT(expression1, expression2, cmp_class) \
    LEST_ASSERT_CUSTOM_CMP(lest::Compare::GT, expression1, expression2, cmp_class)

#define ACMP_GE(expression1, expression2, cmp_class) \
    LEST_ASSERT_CUSTOM_CMP(lest::Compare::GE, expression1, expression2, cmp_class)

#define ACMP_LT(expression1, expression2, cmp_class) \
    LEST_ASSERT_CUSTOM_CMP(lest::Compare::LT, expression1, expression2, cmp_class)

#define ACMP_LE(expression1, expression2, cmp_class) \
    LEST_ASSERT_CUSTOM_CMP(lest::Compare::LE, expression1, expression2, cmp_class)

static int RUN()
{
#ifdef __cplusplus
    lest::testing::UnitTest::GetAllInstance()->RunAllTest();
#endif
    return lest::testing::UnitTest::GetAllInstance()->GenerateReport(true);
}

#endif // LEST_H
