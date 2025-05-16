#include <lest.h>

int fact(uint n)
{
    if(n == 0)
    {
        return 1;
    }
    return fact(n - 1) * n;
}

int naive_fact(uint n)
{
    uint tmp = 1;
    for(int i = 0; i < n; i ++)
    {
        tmp *= (i + 1);
    }
    return tmp;
}

class DemoFixture: public lest::testing::Test
{
public:
    int var = 0;
protected:
    void Setup() override
    {
        var ++;
    }
    void TearDown() override
    {
        var --;
    }

};

TEST(Fact, pos)
{
    for(int i = 0; i < 10; i ++)
    {
        EQ(fact(i), naive_fact(i));
    }
}

TEST_F(DemoFixture, fun)
{
    lest::utils::Timer t;
    EQ(var, 1);

    t.sleep_for_seconds(5);
    EQ(var, 1);
    
}