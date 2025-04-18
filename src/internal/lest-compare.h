#ifndef LEST_COMPARE_H
#define LEST_COMPARE_H
#include "internal/lest-define.h"
#include "internal/lest-assert.h"

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

	template <typename T>
	int EQImpl(T expression1, T expression2)
	{
		if(expression1 == expression2)
		{
			return 1;
		}
		else 
		{
			// todo raise different error.
			return 0;
		}
	}

	template <typename T>
	int NEImpl(T expression1, T expression2)
	{
		if(expression1 != expression2)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}

	template <typename T>
	int GTImpl(T expression1, T expression2)
	{
		if(expression1 > expression2)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	
	template <typename T>
	int GEImpl(T expression1, T expression2)
	{
		if(expression1 >= expression2)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	
	template <typename T>
	int LEImpl(T expression1, T expression2)
	{
		if(expression1 <= expression2)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}

	template <typename T>
	int LTImpl(T expression1, T expression2)
	{
		if(expression1 < expression2)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}

	template <typename T1, typename T2>
	int CMPImpl(T1 expression1, T2 expression2, Comparor cmp)
	{
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
public:
	virtual int EQ();
	virtual int NE();
	virtual int GT();
	virtual int GE();
	virtual int LT();
	virtual int LE();
};

}; // namespace lest

#endif