#include <lest.h>
#include <vector>

class FooTest: public lest::testing::Test
{
    public:
        std::vector<int> v_;
    protected:
        void Setup() override
        {
            // Setup code here
            v_.push_back(1);
            v_.push_back(2);
        }
        void TearDown() override
        {
            // Cleanup code here
            v_.pop_back();
            v_.pop_back();
        }
};

class MoreFooTest: public FooTest
{
    public:
        std::vector<int> v2_;

    protected:
        void Setup() override
        {
            FooTest::Setup();
            v2_.push_back(1);
        }

        void TearDown() override
        {
            FooTest::TearDown();
        }
};

TEST_F(FooTest, fun)
{
    int a = 1, b = 2;
    EQ(v_.size(), 2);
}

TEST_F(MoreFooTest, lol)
{
    EQ(v2_.size(), 1);
    EQ(v_.size(), 2);
}