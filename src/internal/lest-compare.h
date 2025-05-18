#ifndef LEST_COMPARE_H
#define LEST_COMPARE_H
#include "internal/lest-define.h"
#include "internal/lest-assert.h"
#include "internal/lest-testing.h"
#include "internal/lest-internal.h"
#include <cmath>

namespace lest
{

class Comparor;
/**
 * lest compare class
 * use template to compare result, type cannot be different, 
 * the compare result will be registe to the TestInfo to store,
 * identifier is test_group-test_case
 * also should use macro to manually register the info...
 */
class Compare
{
public:
enum {
	EQ,
	NE,
	LT,
	GT,
	LE,
	GE,
	CMP,
};

public:
	Compare();
	~Compare();

	template <typename T1, typename T2>
	static int EQImpl(T1 expression1, T2 expression2, lest::testing::Test* test, bool is_assert)
	{
		if constexpr (std::is_floating_point<T1>::value && std::is_floating_point<T2>::value)
		{
			if (std::fabs(expression1 - expression2) < 1e-9)
			{
				// LOG_INFO << "TEST PASSED";
				return 1;
			}
		}
		else
		{
			if(expression1 == expression2)
			{
				// LOG_INFO << "TEST PASSED";
				return 1;
			}

		}

		{
			lest::testing::UnitTest::GetAllInstance()->AddFailedTest(test);
			if(is_assert)
			{
				// throw runtime error
                std::ostringstream oss;
                oss << "Assertion failed: " << expression1 << " == " << expression2 << " (" << expression1 << " vs " << expression2 << ")";
				throw std::runtime_error(oss.str());
			}
			else 
			{
				LOG_ERROR << "Expect: " << expression1 << " == " << expression2 << ", But got an !=. "; 
			}
			return 0;
		}
	}

	template <typename T1, typename T2>
	static int NEImpl(T1 expression1, T2 expression2, lest::testing::Test* test, bool is_assert)
	{
		if(expression1 != expression2)
		{
			// LOG_INFO << "TEST PASSED";
			return 1;
		}
		else 
		{
			lest::testing::UnitTest::GetAllInstance()->AddFailedTest(test);
			if(is_assert)
			{
				// throw runtime error
                std::ostringstream oss;
                oss << "Assertion failed: " << expression1 << " != " << expression2 << " (" << expression1 << " vs " << expression2 << ")";
				throw std::runtime_error(oss.str());
			}
			else 
			{
				LOG_ERROR << "Expect: " << expression1 << " != " << expression2 << ", But got an ==. "; 
			}

			return 0;
		}
	}

	template <typename T1, typename T2>
	static int GTImpl(T1 expression1, T2 expression2, lest::testing::Test* test, bool is_assert)
	{
		if(expression1 > expression2)
		{
			// LOG_INFO << "TEST PASSED";
			return 1;
		}
		else 
		{
			lest::testing::UnitTest::GetAllInstance()->AddFailedTest(test);

			if(is_assert)
			{
				// throw runtime error
                std::ostringstream oss;
                oss << "Assertion failed: " << expression1 << " > " << expression2 << " (" << expression1 << " vs " << expression2 << ")";
				throw std::runtime_error(oss.str());
			}
			else 
			{
				LOG_ERROR << "Expect: " << expression1 << " > " << expression2 << ", But got an <=. "; 
			}
			
			return 0;
		}
	}
	
	template <typename T1, typename T2>
	static int GEImpl(T1 expression1, T2 expression2, lest::testing::Test* test, bool is_assert)
	{
		if(expression1 >= expression2)
		{
			// LOG_INFO << "TEST PASSED";
			return 1;
		}
		else 
		{
			lest::testing::UnitTest::GetAllInstance()->AddFailedTest(test);

			if(is_assert)
			{
				// throw runtime error
                std::ostringstream oss;
                oss << "Assertion failed: " << expression1 << " >= " << expression2 << " (" << expression1 << " vs " << expression2 << ")";
				throw std::runtime_error(oss.str());
			}
			else 
			{
				LOG_ERROR << "Expect: " << expression1 << " >= " << expression2 << ", But got an <. "; 
			}
			
			return 0;
		}
	}
	
	template <typename T1, typename T2>
	static int LEImpl(T1 expression1, T2 expression2, lest::testing::Test* test, bool is_assert)
	{
		if(expression1 <= expression2)
		{
			// LOG_INFO << "TEST PASSED";
			return 1;
		}
		else 
		{
			lest::testing::UnitTest::GetAllInstance()->AddFailedTest(test);

			if(is_assert)
			{
				// throw runtime error
                std::ostringstream oss;
                oss << "Assertion failed: " << expression1 << " <= " << expression2 << " (" << expression1 << " vs " << expression2 << ")";
				throw std::runtime_error(oss.str());
			}
			else 
			{
				LOG_ERROR << "Expect: " << expression1 << " <= " << expression2 << ", But got an >. "; 
			}
			
			return 0;
		}
	}

	template <typename T1, typename T2>
	static int LTImpl(T1 expression1, T2 expression2, lest::testing::Test* test, bool is_assert)
	{
		if(expression1 < expression2)
		{
			// LOG_INFO << "TEST PASSED";
			return 1;
		}
		else 
		{
			lest::testing::UnitTest::GetAllInstance()->AddFailedTest(test);

			if(is_assert)
			{
				// throw runtime error
                std::ostringstream oss;
                oss << "Assertion failed: " << expression1 << " < " << expression2 << " (" << expression1 << " vs " << expression2 << ")";
				throw std::runtime_error(oss.str());
			}
			else 
			{
				LOG_ERROR << "Expect: " << expression1 << " < " << expression2 << ", But got an >=. "; 
			}
			
			return 0;
		}
	}

	template <typename T1, typename T2>
	static int CMPImpl(T1 expression1, T2 expression2, const Comparor& cmp, lest::testing::Test* test)
	{
		return 0;
	}
	

	/**
	 * for classic c str
	 */
	int CSTREQImpl(const char *str1, const char *str2)
	{
		return std::strcmp(str1, str2);
	}
	
};

class Comparor
{
public:
	Comparor() = default;
// public:
// 	virtual int EQ();
// 	virtual int NE();
// 	virtual int GT();
// 	virtual int GE();
// 	virtual int LT();
// 	virtual int LE();
};

}; // namespace lest

#endif