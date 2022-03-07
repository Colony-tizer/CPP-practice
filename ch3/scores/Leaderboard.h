#ifndef LEADERBOARD_H_

#define LEADERBOARD_H_

#include "GameEntry.h"

class Leaderboard {
    private:
        enum CheckMode {
            BothCheck = 0x11,
            ScoreCheck = 0x01,
            NameCheck = 0x10
        };

    public:
        Leaderboard(int cap = 10);
        ~Leaderboard();
        void add(const GameEntry &entry);
        GameEntry remove(int score);
        GameEntry remove(const GameEntry &entry);
        std::string toString() const;

    private:
        GameEntry remove(const GameEntry &entry, CheckMode mode);
        GameEntry removeAt(int idx);

    private:
        GameEntry *scores;
        int capacity;
        int scoresLen;
};
#endif