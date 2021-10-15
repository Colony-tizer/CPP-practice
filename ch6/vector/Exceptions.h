#include <exception>

struct EmptyVectorError : public std::exception {
    const char* what() { return "Empty Vector Error: there are no items in vector"; }
};

struct OutOfRangeError : public std::exception {
    const char* what() { return "Out Of Range Error: input index is out of range"; }
};
