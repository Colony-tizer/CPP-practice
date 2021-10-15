#include "SList.h"
#include <string>
int main() {
    SList<std::string> a;
    a.addFront(">");
    a.addFront("<");
    a.addFront("!asdas!");
    a.popFront();
    a.popFront();
    a.popFront();
    a.popFront();
    return 0;
}