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
        }
};

TEST_F(FooTest, fun)
{
    int a = 1, b = 2;
    EQ(v_.size(), 2);
}