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
	LE,
	GE,
	CMP,
};

public:
	Compare();
	~Compare();
	template<typename T>
	int EqImpl(T expression1, T expression2)
	{
		return expression1 == expression2;
	}
	
private:

};

}; // namespace lest
#endif