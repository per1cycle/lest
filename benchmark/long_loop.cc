#include <lest.h>

lest::utils::Timer global_timer;

TEST(Benchmark, 1000)
{
    const int N = 1000;
    global_timer.start();
    for(int i = 0; i < N; i ++)
        TRUE(1);
    global_timer.stop();
    global_timer.just_report_time();
    global_timer.reset();
}


TEST(Benchmark, 1000000)
{
    const int N = 1000000;
    global_timer.start();
    for(int i = 0; i < N; i ++)
        TRUE(1);
    global_timer.stop();
    global_timer.just_report_time();
    global_timer.reset();

}


TEST(Benchmark, 10000000)
{
    const int N = 10000000;
    global_timer.start();
    for(int i = 0; i < N; i ++)
        TRUE(1);
    global_timer.stop();
    global_timer.just_report_time();
    global_timer.reset();

}


TEST(Benchmark, 1000000000)
{
    const int N = 1000000000;
    global_timer.start();
    for(int i = 0; i < N; i ++)
        TRUE(1);
    global_timer.stop();
    global_timer.just_report_time();
    global_timer.reset();

}