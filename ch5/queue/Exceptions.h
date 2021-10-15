#include <exception>

struct QueueEmptyError : std::exception {
    const char* what() { return "Queue Empty Error: there are no items in the queue"; }
};

struct QueueFullError : std::exception {
    const char* what() { return "Queue Full Error: there are maximum number of items in the queue"; }
};