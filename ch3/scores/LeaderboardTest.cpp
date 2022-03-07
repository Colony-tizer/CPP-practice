#include "GameEntry.h"
#include "Leaderboard.h"
#include <iostream>
#include <string>

using namespace std;

void addTest(Leaderboard &test) {
    cout << "adding 10..." << endl;
    test.add(GameEntry(10, "Bill"));
    cout << test.toString() << endl << endl;;
    cout << "adding 11..." << endl;
    test.add(GameEntry(11, "Bill"));
    cout << test.toString() << endl << endl;;
    cout << "adding 12..." << endl;
    test.add(GameEntry(12, "Bill"));
    cout << test.toString() << endl << endl;;
}

void removeTest(Leaderboard &test) {
    GameEntry removed;
    cout << "Removing............." << endl;
    removed = test.remove(10);
    cout << "Removed: " << removed.toString() << endl << endl;
    cout << test.toString() << endl << endl;;
    removed = test.remove(12);
    cout << "Removed: " << removed.toString() << endl << endl;
    cout << test.toString() << endl << endl;;
    removed = test.remove(11);
    cout << "Removed: " << removed.toString() << endl << endl;
    cout << test.toString() << endl << endl;;
}

void addBigNumbersTest(Leaderboard &test) {
    cout << "Created new leaderboard: " << endl;
    test.add(GameEntry(1105, "Mike>"));
    test.add(GameEntry(750, "Rob"));
    test.add(GameEntry(720, "Paul"));
    test.add(GameEntry(660, "Anna"));
    test.add(GameEntry(590, "Rose"));
    test.add(GameEntry(510, "Jack"));
    cout << test.toString() << endl << endl;

    cout << "Test. Adding 740" << endl;
    test.add(GameEntry(740, "Jill"));
    cout << test.toString() << endl << endl;
}

void addNegativeNumbersTest(Leaderboard &test) {
    test.add(GameEntry(-1105, "Mike>"));
    test.add(GameEntry(-750, "Rob"));
    cout << test.toString() << endl << endl;
}

void addNegativeNumbersAndOnePositiveTest(Leaderboard &test) {
    test.add(GameEntry(-1105, "Mike>"));
    test.add(GameEntry(-750, "Rob"));
    test.add(GameEntry(720, "Paul"));
    test.add(GameEntry(-1200, "Paul"));
    cout << test.toString() << endl << endl;
}

void removeExactEntryTest(Leaderboard &test) {
    GameEntry removed = test.remove(GameEntry(-1200, "Paul"));
    cout << test.toString() << endl << endl;
    cout << removed.toString() << endl << endl;
}

int main() {
    Leaderboard *obj = new Leaderboard(3);

    addTest(*obj);
    removeTest(*obj);
    cout << "Removing from empty:" << endl << endl;
    removeTest(*obj);

    delete obj;

    obj = new Leaderboard();
    addBigNumbersTest(*obj);

    delete obj;

    obj = new Leaderboard();
    addNegativeNumbersTest(*obj);

    delete obj;

    obj = new Leaderboard(3);
    addNegativeNumbersAndOnePositiveTest(*obj);
    removeTest(*obj);

    delete obj;

    return 0;
}