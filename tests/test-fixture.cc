#include <lest.h>

class FastTest: public lest::testing::Test
{
public:
    using lest::testing::Test::Test;
    lest::utils::Timer t;
public:
    void Setup() override
    {
        t.start();
    }
    void TearDown() override
    {
        t.stop();
        if(t.elapse_in_second() > 3)
        {
            LOG_WARNING << "Test takes too long.";
        }
    }
};

class FunTest: public FastTest
{
public:
    using FastTest::FastTest;
    int x_;
public:
    void Setup() override
    {
        FastTest::Setup();
        x_ = 1;
    }

    void TearDown() override
    {
        x_ = 0;
        FastTest::TearDown();
    }

};

TEST_F(FunTest, fast)
{
    lest::utils::Timer fun_timer;
    fun_timer.sleep_for_seconds(2);
    EQ(x_, 1);
}


TEST_F(FunTest, slow)
{
    lest::utils::Timer fun_timer;
    fun_timer.sleep_for_seconds(5);
    EQ(x_, 1);
}