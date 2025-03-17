
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
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

TEST(FactorialTest, Positive)
{
    EQ(Factorial(0), 1);
    EQ(Factorial(1), 1);
    EQ(Factorial(2), 2);
    EQ(Factorial(3), 6);
    EQ(Factorial(4), 24);
    EQ(Factorial(5), 120);
}

TEST(FactorialTest, Negative)
{
    std::cout << "FactorialTest Negative\n";
    EQ(Factorial(-1), 1);  // Assuming your function treats negative inputs as 1
    EQ(Factorial(-5), 1);
}

TEST(IsPrimeTest, PrimeNumbers)
{
    std::cout << "IsPrimeTest PrimeNumbers\n";
    EQ(IsPrime(2), 1);
    EQ(IsPrime(3), 1);
    EQ(IsPrime(5), 1);
    EQ(IsPrime(7), 1);
    EQ(IsPrime(11), 1);
}

TEST(IsPrimeTest, NonPrimeNumbers)
{
    std::cout << "IsPrimeTest NonPrimeNumbers\n";
    EQ(IsPrime(0), 0);
    EQ(IsPrime(1), 0);
    EQ(IsPrime(4), 0);
    EQ(IsPrime(6), 0);
    EQ(IsPrime(9), 0);
    EQ(IsPrime(10), 0);
}