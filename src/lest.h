#ifndef LEST_H
#define LEST_H

/**
 * during the development 2025/03/07
 * i think most of the definition should be moved here.
 */

#include "internal/lest-compare.h"
#include "internal/lest-define.h"
#include "internal/lest-internal.h"
#include "internal/lest-testing.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>

// every time call the TEST macro will register a unit test class
// and RUN will run all the registered unit test classes,
// test is separated by test_group and test_name.
#define TEST(test_group, test_name) LEST_TEST(test_group, test_name)

#define LEST_TEST(test_group, test_name) \
    LEST_TEST_(test_group, test_name, lest::testing::Test)

/**
 * assertation for different expressions,
 * theres
 * - EQ =
 * - GE >=
 * - LE <=
 * - NE !=
 * - CMP user can design their own compare condition, need pass compare class;
 */

#define EQ(expression1, expression2) \
    LEST_ASSERT(lest::Compare::EQ, expression1, expression2)

#define GE(expression1, expression2) \
    LEST_ASSERT(lest::Compare::GE, expression1, expression2)

#define LE(expression1, expression2) \
    LEST_ASSERT(lest::Compare::LE, expression1, expression2)

#define NE(expression1, expression2) \
    LEST_ASSERT(lest::Compare::NE, expression1, expression2)

#define CMP(expression1, expression2, cmp_class) \
    LEST_ASSERT(lest::Compare::CMP, expression1, expression2, cmp_class)

static int RUN()
{
    lest::testing::UnitTest::GetAllInstance()->RunAllTest();
}

// micro log migrate.
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
    constexpr static const char* level_name[Level::NUM] = {
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

#endif // LEST_H
