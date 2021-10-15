#ifndef GAMEENTRY_H_

#define GAMEENTRY_H_

#include <string>

using namespace std;

class GameEntry {
    public:
        GameEntry(int score = 0, const string &name = "") : score(score), name(name) {}
        GameEntry(const GameEntry &entry) : score(entry.score), name(entry.name) {}
        GameEntry(GameEntry &entry) : score(entry.score), name(entry.name) {}
        int getScore() const {return score;}
        string getName() const {return name;}
        string toString() const {
            return name + " | " + to_string(score);
        }
    private:
        int score;
        string name;
};
#endif