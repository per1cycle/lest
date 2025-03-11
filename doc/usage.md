# How to use lest in your project?

## First
include "lest.h" in the test target:

super quick demo belike:
```cpp

// for TEST macro.
#include <lest.h>

// you can include you own stuff for testing.
#include <your-awesome.h>

// consumpt that this function is used for add currrent n with 1.
extern int ExternalAwesome(int n);


int Square(int u)
{
    return u * u;
}

TEST(SquareGroup, Positive) {
    EQ(1, Square(1));
    EQ(4, Square(2));
}

TEST(SquareGroup, Negative) {
    EQ(1, Square(-1));
    EQ(4, Square(-2));
}

```

and the output result is belike:
```
Start Testing...


```
