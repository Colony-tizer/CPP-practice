#include <exception>

struct ListEmptyError : std::exception {
    const char* what() {
        return "List Empty Error: there are no items in the list";
    }
};
