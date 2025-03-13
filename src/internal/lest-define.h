#ifndef LEST_DEFINE_H
#define LEST_DEFINE_H
// define version 

#define LEST_VERSION_MAJOR "0"
#define LEST_VERSION_MINOR "1"
#define LEST_STRINGIFY_VERSION(major, minor) major "." minor
#define LEST_VERSION LEST_STRINGIFY_VERSION(LEST_VERSION_MAJOR, LEST_VERSION_MINOR)

/**
 * global debug info
 */
static const int debug_ = std::atoi(std::getenv("DEBUG"));

// define API
#ifdef LEST_API 
// do nothing
#else
#define LEST_API
#endif

#endif // LEST_DEFINE_H