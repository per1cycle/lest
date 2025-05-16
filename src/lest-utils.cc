#include "internal/lest-utils.h"
#include <chrono>
#include <thread>

#define CPU
#if defined(CUDA)
#define Event_t cudaEvent_t
#define EventCreate(event) cudaEventCreate((event))
#define EventRecord(event, value) cudaEventRecord((event), (value))
#define EventSynchronize(event) cudaEventSynchronize((event))
#define EventElapsedTime(elapse, start, end) cudaEventElapsedTime((elapse), (start), (end)) 
#define EventDestroy(event) cudaEventDestroy((event))
#define Malloc()
#define Free()
#define Memcpy()
#define D2H 0
#define H2D 1
#elif defined(HIP)
#define Event_t hipEvent_t
#define EventCreate(event) hipEventCreate ((event))
#define EventRecord(event, value) hipEventRecord((event), (value))
#define EventSynchronize(event) hipEventSynchronize((event))
#define EventElapsedTime(elapse, start, end) hipEventElapsedTime((elapse), (start), (end)) 
#define EventDestroy(event) hipEventDestroy((event))
#define Malloc()
#define Free()
#define Memcpy()
#define D2H 0
#define H2D 1
#elif defined(CPU)
#define Event_t std::chrono::system_clock::time_point
#define EventCreate(event) 
#define EventRecord(event, value) (event) = std::chrono::system_clock::now()
#define EventSynchronize(event)
#define EventElapsedTime(elapse, start, end) *(elapse) = std::chrono::duration_cast<std::chrono::milliseconds>((end) - (start)).count()
#define EventDestroy(event)
#endif

namespace lest
{
namespace utils
{
    
std::string current_time()
{
    // Get current time
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    // Create a string stream to format the time
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y-%m-%d-%H:%M:%S");

    return oss.str();
}

Timer::Timer()
{
    EventCreate(&start_);
    EventCreate(&stop_);
    elapse_in_milisecond_ = 0.0f;
}

Timer::~Timer()
{
    EventDestroy(start_);
    EventDestroy(stop_);
}

void Timer::start()
{
    EventRecord(start_, 0);
}

void Timer::stop()
{
    EventRecord(stop_, 0);
    EventSynchronize(stop_);
    EventElapsedTime(&elapse_in_milisecond_, start_, stop_);
}

float Timer::elapse_in_milisecond()
{
    return elapse_in_milisecond_; // convert to second
}

float Timer::elapse_in_second()
{
    return elapse_in_milisecond_ / 1000.0f; // convert to second
}

void Timer::reset()
{
    elapse_in_milisecond_ = 0.0f;
}

void Timer::just_report_time()
{
    std::cout 
            << ">> Problem: Just report    \t" << std::endl
            << "Time elapse(in second):    \t" << elapse_in_second() << "s."<< std::endl
            << "Time elapse(in milisecond):\t" << elapse_in_milisecond() << "ms." << std::endl;
}

void Timer::sleep_for_seconds(int seconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 * seconds));
}

}

}