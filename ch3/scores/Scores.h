#ifndef SCORES_H_

#define SCORES_H_

#include "GameEntry.h"

using namespace std;


class Scores {
    private:
        enum CheckMode {
            BothCheck = 0x11,
            ScoreCheck = 0x01,
            NameCheck = 0x10
        };
    public:
        Scores(int cap = 10);
        void add(const GameEntry &entry);
        GameEntry remove(int score);
        GameEntry remove(const GameEntry &entry);
        string toString() const;
        ~Scores();
    private:
        GameEntry remove(const GameEntry &entry, CheckMode mode);
        GameEntry removeAt(int ind);
    private:
        GameEntry *scores;
        int capacity;
        int scoresLen;
};
#endif