
/* 
compute n! for n
example:
0! = 1
1! = 1
2! = 1 * 2 = 2
3 ! = 1 * 2 * 3 = 6
*/
#include "lest.h"
int Factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/*
detect if n is a prime number
example:
isprime(2) = 1
isprime(3) = 1
isprime(4) = 0
*/
int IsPrime(int n) {

}

TEST(FactorialTest, Positive)
{
    EXPECT_EQ(Factorial(1), 1);
    EXPECT_EQ(Factorial(0), 0);
}

