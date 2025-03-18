#ifndef LEST_DEFINE_H
#define LEST_DEFINE_H
// define version 
#define LEST_VERSION_MAJOR "0"
#define LEST_VERSION_MINOR "1"
#define LEST_STRINGIFY_VERSION(major, minor) major "." minor
#define LEST_VERSION LEST_STRINGIFY_VERSION(LEST_VERSION_MAJOR, LEST_VERSION_MINOR)

#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <cstring>

/**
 * global debug info
 */
static const int debug_ = 0;

// define API
#ifdef LEST_API 
// do nothing
#else
#define LEST_API
#endif

// micro log migrate.
// https://github.com/per1cycle/microlog/blob/main/log.hh
enum Level { INFO = 0,
    WARNING,
    ERROR,
    NUM };
class Timestamp {
public:
    Timestamp() { }
    // Timestamp(size_t time);
    ~Timestamp() { }

public:
    size_t now()
    {
        auto timestamp = std::chrono::seconds(std::time(NULL));
        return static_cast<size_t>(timestamp.count());
    }
    std::string toString()
    {
        std::string tmp = std::to_string(now());
        return tmp;
    }
    std::string toFormatString()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        return ss.str();
    }
};

class LogImpl {
public:
    LogImpl() { }
    LogImpl(const char* file, int line, Level level)
        : file_(file)
        , line_(line)
        , level_(level)
        , timestamp_()
    {
        char log_header[1024];
        snprintf(log_header, sizeof(log_header), "[%s] %s\t%s:%d ",
            level_name[level_], timestamp_.toFormatString().c_str(), file_,
            line_);
        oss_ << log_header;
    }

    ~LogImpl() { }

public:
    void finish() { oss_ << '\n'; }

public:
    Level level_;
    std::ostringstream oss_;
    const char* file_;
    int line_;
    Timestamp timestamp_;
    static const char* level_name[Level::NUM] = {
        "\033[1;32mINFO\033[1;37m",
        "\033[1;33mWARNING\033[1;37m",
        "\033[1;31mERROR\033[1;37m",
    };
};

class Log {
public:
    Log()
        : impl_(new LogImpl(__FILE__, __LINE__, Level::INFO))
    {
    }
    Log(Level level)
        : impl_(new LogImpl(__FILE__, __LINE__, level))
    {
    }
    Log(const char* file, int line, Level level)
        : impl_(new LogImpl(file, line, level))
    {
    }
    ~Log()
    {
        impl_->finish();
        std::string buffer(impl_->oss_.str());
        ::fwrite(buffer.data(), 1, buffer.size(), stdout);
    }
    std::ostream& stream() { return impl_->oss_; }
public:
    std::shared_ptr<LogImpl> impl_;
}; // class Log

// @ref https://stackoverflow.com/questions/8487986/file-macro-shows-full-path
#define __FILENAME__ \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG_INFO Log(__FILENAME__, __LINE__, Level::INFO).stream()
#define LOG_WARNING Log(__FILENAME__, __LINE__, Level::WARNING).stream()
#define LOG_ERROR Log(__FILENAME__, __LINE__, Level::ERROR).stream()
#define LOG LOG_INFO

#endif // LEST_DEFINE_H