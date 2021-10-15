#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <exception>

struct StackEmptyException : protected std::exception {
    const char* what() {
        return "Empty Stack Error: There are no items in stack";
    }
};

struct StackFullException : protected std::exception {
    const char* what() {
        return "Full Stack Error: Stack is full";
    }
};
#endif