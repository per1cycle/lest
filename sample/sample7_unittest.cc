#include <lest.h>
#include <vector>
#include <unistd.h>

class FastTest: public lest::testing::Test
{
    public:
        std::vector<int> v_;
        lest::utils::Timer t;
        using lest::testing::Test::Test;

    protected:
        void Setup() override
        {
            t.start();
            // Setup code here
            v_.push_back(1);
            v_.push_back(2);
        }
        void TearDown() override
        {
            // Cleanup code here
            v_.pop_back();
            v_.pop_back();
            t.stop();
            if(t.elapse_in_second() > 1.0f)
            {
                LOG_WARNING << "Test takes too long.";
            }
        }
};

// class MoreFooTest: public FastTest
// {
//     public:
//         std::vector<int> v2_;

//     protected:
//         void Setup() override
//         {
//             FastTest::Setup();
//             v2_.push_back(1);
//         }

//         void TearDown() override
//         {
//             FastTest::TearDown();
//         }
// };

TEST_F(FastTest, fun)
{
    int a = 1, b = 2;
    lest::utils::Timer t;
    t.sleep_for_seconds(3);

    EQ(v_.size(), 2);
}

// TEST_F(MoreFooTest, lol)
// {
//     EQ(v2_.size(), 1);
//     EQ(v_.size(), 2);
// }