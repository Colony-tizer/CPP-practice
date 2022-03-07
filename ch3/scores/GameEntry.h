#ifndef GAMEENTRY_H_

#define GAMEENTRY_H_

#include <string>

class GameEntry {
    public:
        GameEntry(int score = 0, const std::string &name = "") : score(score), name(name) {}
        GameEntry(const GameEntry &entry) : score(entry.score), name(entry.name) {}
        GameEntry(GameEntry &entry) : score(entry.score), name(entry.name) {}
        int getScore() const {return score;}
        std::string getName() const {return name;}
        std::string toString() const {
            return "\t" + name + "\t|\t" + std::to_string(score);
        }

    private:
        int score;
        std::string name;
};
#endif