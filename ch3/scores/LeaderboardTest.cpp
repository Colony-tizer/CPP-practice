#include "GameEntry.h"
#include "Leaderboard.h"

#include <iostream>
#include <string>

using namespace std;

void addTest(Leaderboard &testObj) {
    cout << "adding 10..." << endl;
    testObj.add(GameEntry(10, "Bill"));

    cout << testObj.toString() << endl << endl;
    cout << "adding 11..." << endl;

    testObj.add(GameEntry(11, "Bill"));
    cout << testObj.toString() << endl << endl;

    cout << "adding 12..." << endl;
    testObj.add(GameEntry(12, "Bill"));

    cout << testObj.toString() << endl << endl;
}

void removeTest(Leaderboard &testObj) {
    GameEntry removedItem;
    cout << "Removing............." << endl;
    removedItem = testObj.findWithScore(10); 
    testObj.removeWithScore(10);
    cout << "Removed: " << removedItem.toString() << endl << endl;
    cout << testObj.toString() << endl << endl;

    removedItem = testObj.findWithName("Bill");
    testObj.removeEntry(removedItem);
    cout << "Removed: " << removedItem.toString() << endl << endl;
    cout << testObj.toString() << endl << endl;

    removedItem = testObj.findWithName("Bill");
    testObj.removeWithName("Bill");
    cout << "Removed: " << removedItem.toString() << endl << endl;

    cout << testObj.toString() << endl << endl;
}

void addBigNumbersTest(Leaderboard &testObj) {
    cout << "Created new leaderboard: " << endl;
    testObj.add(GameEntry(1105, "Mike>"));
    testObj.add(GameEntry(750, "Rob"));
    testObj.add(GameEntry(720, "Paul"));
    testObj.add(GameEntry(660, "Anna"));
    testObj.add(GameEntry(590, "Rose"));
    testObj.add(GameEntry(510, "Jack"));
    cout << testObj.toString() << endl << endl;

    cout << "Test. Adding 740" << endl;
    testObj.add(GameEntry(740, "Jill"));

    cout << testObj.toString() << endl << endl;
}

void addNegativeNumbersTest(Leaderboard &testObj) {
    cout << "Created new leaderboard: " << endl;
    testObj.add(GameEntry(-1105, "Mike>"));
    testObj.add(GameEntry(-750, "Rob"));
    cout << testObj.toString() << endl << endl;

    cout << testObj.toString() << endl << endl;
}

void testCapacity(Leaderboard &testObj) {
    cout << "Add Negative Numbers And One Positive Test: " << endl;
    testObj.add(GameEntry(-1105, "Mike>"));
    testObj.add(GameEntry(-750, "Rob"));
    testObj.add(GameEntry(720, "Paul"));

    cout << testObj.toString() << endl << endl;
    
    cout << "Adding -1200, Paul: " << endl;
    testObj.add(GameEntry(-1200, "Paul"));

    cout << testObj.toString() << endl << endl;
}

void removeExactEntryTest(Leaderboard &testObj) {
    cout << "Removing Entry: -1200, Paul" << endl;
    const GameEntry exactEntry(-1200, "Paul");

    GameEntry removedItem = testObj.findEntry(exactEntry);
    testObj.removeEntry(removedItem);

    cout << testObj.toString() << endl << endl;

    cout << "Removed item: " << removedItem.toString() << endl << endl;
}

int main() {
    Leaderboard leaderboard(3);

    addTest(leaderboard);
    removeTest(leaderboard);
    cout << "Removing from empty:" << endl << endl;
    removeTest(leaderboard);

    leaderboard = Leaderboard();
    addBigNumbersTest(leaderboard);

    leaderboard = Leaderboard();
    addNegativeNumbersTest(leaderboard);

    leaderboard = Leaderboard(3);
    testCapacity(leaderboard);
    removeExactEntryTest(leaderboard);

    return 0;
}