#include <lest.h>


TEST(Benchmark, 1000)
{
    int N = 1000;
    lest::utils::Timer t;
    t.start();
    for(int i = 0; i < N; i ++)
    {
        GT(2, 1);
        if(i == N - 23)
            NE(2, 3);
    }
    t.stop();
    t.just_report_time();
    t.reset();
}


TEST(Benchmark, 1000000)
{
    int N = 1000000;
    lest::utils::Timer t;

    t.start();
    for(int i = 0; i < N; i ++)
    {
        GT(2, 1);
        if(i == N - 23)
            NE(2, 3);
    }
    t.stop();
    t.just_report_time();
    t.reset();

}


TEST(Benchmark, 10000000)
{
    int N = 10000000;
    lest::utils::Timer t;

    t.start();
    for(int i = 0; i < N; i ++)
    {
        GT(2, 1);
        if(i == N - 23)
            NE(2, 3);
    }
    t.stop();
    t.just_report_time();
    t.reset();

}


TEST(Benchmark, 1000000000)
{
    int N = 1000000000;
    lest::utils::Timer t;

    t.start();
    for(int i = 0; i < N; i ++)
    {
        GT(2, 1);
        if(i == N - 23)
            NE(2, 2);
    }
    t.stop();
    t.just_report_time();
    t.reset();

}