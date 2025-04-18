#include "internal/lest-define.h"

const char* LogImpl::level_name[Level::NUM] = {
    "\033[1;32mINFO\033[1;37m",
    "\033[1;33mWARNING\033[1;37m",
    "\033[1;31mERROR\033[1;37m",
    // "[INFO]",
    // "\033[1;33mWARNING\033[1;37m",
    // "\033[1;31mERROR\033[1;37m",
};