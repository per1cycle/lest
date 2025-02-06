#ifndef LEAST_TESTING_H
#define LEAST_TESTING_H

namespace lest
{
namespace testing
{

class  Test
{
public:
Test();
virtual ~Test();

private:
virtual void TestBody() = 0;


};

}; // namespace testing

}; // namespace lest

#endif // LEAST_TESTING_H