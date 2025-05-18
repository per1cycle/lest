#include <lest.h>
#include <vector>
#include <unistd.h>

class FastTest: public lest::testing::Test
{
    public:
        std::vector<int> v_;
        time_t st;
        FastTest(const std::string& test_group, const std::string& test_name)
        : lest::testing::Test(test_group, test_name) {}
    protected:
        void Setup() override
        {
            // Setup code here
            v_.push_back(1);
            v_.push_back(2);
            st = time(nullptr);

        }
        void TearDown() override
        {
            // Cleanup code here
            v_.pop_back();
            v_.pop_back();
            const time_t end_time = time(nullptr);
            std::cout << "++++Test takes too long." << std::endl;
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