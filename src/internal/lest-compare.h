#ifndef LEST_COMPARE_H
#define LEST_COMPARE_H
#include "internal/lest-define.h"
#include "internal/lest-assert.h"

namespace lest
{
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
	virtual int CMP() = 0;
	virtual int EQ() = 0;
	virtual int NE() = 0;
	virtual int GT() = 0;
	virtual int GE() = 0;
	virtual int LT() = 0;
	virtual int LE() = 0;
};

}; // namespace lest

#endif