#include "GameEntry.h"
#include "Scores.h"
#include <iostream>
#include <string>

void test1(Scores &test) {
    cout<<"adding 10..."<<endl;
    test.add(GameEntry(10, "Bill"));
    cout<<test.toString();
    cout<<"adding 11..."<<endl;
    test.add(GameEntry(11, "Bill"));
    cout<<test.toString();
    cout<<"adding 12..."<<endl;
    test.add(GameEntry(12, "Bill"));
    cout<<test.toString();
}
void test1Rem(Scores &test) {
    GameEntry removed;
    cout<<"Removing_______________"<<endl;
    removed = test.remove(10);
    cout<<"Removed: "<<removed.toString()<<endl<<test.toString();
    removed = test.remove(12);
    cout<<"Removed: "<<removed.toString()<<endl<<test.toString();
    removed = test.remove(11);
    cout<<"Removed: "<<removed.toString()<<endl<<test.toString();
}
void test2(Scores &test) {
    test.add(GameEntry(1105, "Mike>"));
    test.add(GameEntry(750, "Rob"));
    test.add(GameEntry(720, "Paul"));
    test.add(GameEntry(660, "Anna"));
    test.add(GameEntry(590, "Rose"));
    test.add(GameEntry(510, "Jack"));
    cout<<test.toString();
    cout<<"test adding 740"<<endl;
    test.add(GameEntry(740, "Jill"));
    cout<<test.toString();
}

void test3(Scores &test) {
    test.add(GameEntry(-1105, "Mike>"));
    test.add(GameEntry(-750, "Rob"));
    test.add(GameEntry(720, "Paul"));
    cout<<test.toString();
}
void test4(Scores &test) {
    test.add(GameEntry(-1105, "Mike>"));
    test.add(GameEntry(-750, "Rob"));
    test.add(GameEntry(720, "Paul"));
    test.add(GameEntry(-1200, "Paul"));
    cout<<test.toString();
}
void test4Rem(Scores &test) {
    GameEntry removed = test.remove(GameEntry(-1200, "Paul"));
    cout<<test.toString();
    cout<<removed.toString();
}
int main() {
    Scores *obj = new Scores(3);
    test1(*obj);
    test1Rem(*obj);
    cout<<"Removing from empty:"<<endl;
    test1Rem(*obj);

    obj = new Scores();
    test2(*obj);

    obj = new Scores();
    test3(*obj);

    obj = new Scores(3);
    test4(*obj);
    test4Rem(*obj);

    return 0;
}