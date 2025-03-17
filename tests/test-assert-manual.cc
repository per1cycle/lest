#include <lest.h>

int fib(int n)
{
    if(n < 0)
        return -1;
    if(n == 0)
        return 1;
    else 
        return n * fib(n - 1);
}

TEST(FibTest, PROPERTY_POS)
{

}
// TEST(fib(1), 1);