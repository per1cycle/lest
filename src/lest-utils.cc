#include "internal/lest-utils.h"

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

}

}