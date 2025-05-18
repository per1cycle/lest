#ifndef LEST_UTILS_H
#define LEST_UTILS_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <chrono>
#define CPU
#if defined(CUDA)
#define Event_t cudaEvent_t
#elif defined(HIP)
#define Event_t hipEvent_t
#elif defined(CPU)
#define Event_t std::chrono::system_clock::time_point
#endif

namespace lest
{
namespace utils
{

std::string current_time();


class Timer
{
public:
    Timer();
    

    void start();

    void stop();

    // get elapsed time in second
    float elapse_in_milisecond();

    float elapse_in_second();

    void reset();

    void just_report_time();

    void sleep_for_seconds(int seconds);

    ~Timer();
    
private:
    Event_t start_, stop_;
    float elapse_in_milisecond_;
};

}

}

#endif