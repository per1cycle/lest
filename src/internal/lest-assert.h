#ifndef LEAST_ASSERT_H
#define LEAST_ASSERT_H

#include <string>
#include <stdexcept>
#include <sstream>

#include "internal/lest-define.h"
namespace lest {

class AssertionError : public std::runtime_error {
public:
    explicit AssertionError(const std::string& message) : std::runtime_error(message) {}
};

class Assert {
public:
    static void AreEqual(int expected, int actual, const std::string& message = "") {
        if (expected != actual) {
            std::ostringstream error;
            error << "Expected: " << expected << ", but got: " << actual;
            if (!message.empty()) {
                error << " - " << message;
            }
            throw AssertionError(error.str());
        }
    }

    static void AreEqual(const std::string& expected, const std::string& actual, const std::string& message = "") {
        if (expected != actual) {
            std::ostringstream error;
            error << "Expected string: \"" << expected << "\", but got: \"" << actual << "\"";
            if (!message.empty()) {
                error << " - " << message;
            }
            throw AssertionError(error.str());
        }
    }

    static void IsTrue(bool condition, const std::string& message = "") {
        if (!condition) {
            std::string error = "Expected true but got false";
            if (!message.empty()) {
                error += " - " + message;
            }
            throw AssertionError(error);
        }
    }

    static void IsFalse(bool condition, const std::string& message = "") {
        if (condition) {
            std::string error = "Expected false but got true";
            if (!message.empty()) {
                error += " - " + message;
            }
            throw AssertionError(error);
        }
    }
};

} // namespace lest

#endif // LEAST_ASSERT_H