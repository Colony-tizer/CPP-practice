#ifndef LEADERBOARD_H_

#define LEADERBOARD_H_

#include "GameEntry.h"

class Leaderboard {
    private:
        const int DEFAULT_SEARCH_SCORE = INT32_MIN;
        const std::string DEFAULT_SEARCH_NAME = "NO_MATCH";

        enum MatchMode {
            Exact = 0x11,
            Score = 0x01,
            Name = 0x10
        };

    public:
        Leaderboard(int cap = 10);
        Leaderboard(const Leaderboard& copyObj);
        ~Leaderboard();

        Leaderboard& operator=(const Leaderboard& copyObj) ;

        GameEntry findWithName(const std::string name);
        GameEntry findWithScore(const int score);
        GameEntry findEntry(const GameEntry &entry, const MatchMode searchMode = MatchMode::Exact);

        void add(const GameEntry &entry);
        void removeWithName(const std::string name);
        void removeWithScore(const int score);
        void removeEntry(const GameEntry &entry);

        std::string toString() const;

    private:
        int getEntryIdx(const GameEntry &searchEntry, const MatchMode& searchMode);
        void deepCopy(const Leaderboard& copyObj);
        void remove(const GameEntry &entry, const MatchMode searchMode);
        void removeAt(size_t idx);

    private:
        GameEntry *scores;
        size_t capacity;
        size_t scoresLen;
        bool isInited = false;
};

#endif