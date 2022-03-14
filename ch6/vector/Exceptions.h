#include <exception>

struct EmptyVectorError : public std::exception {
    const char* what() { return "Empty Vector Error: There are no items in the vector"; }
};

struct OutOfRangeError : public std::exception {
    const char* what() { return "Out Of Range Error: Input index is out of the range"; }
};
