#ifndef LEST_COMPARE_H
#define LEST_COMPARE_H

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

private:

};

}; // namespace lest
