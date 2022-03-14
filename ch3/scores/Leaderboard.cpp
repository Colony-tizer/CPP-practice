#include "Leaderboard.h"

Leaderboard::Leaderboard(int cap /* = 10*/) {
    capacity = cap;
    if (cap < 0) capacity = 10;

    scoresLen = 0;
    scores = new GameEntry[cap];
    
    isInited = true;
}

Leaderboard::Leaderboard(const Leaderboard& copyObj) {
    deepCopy(copyObj);
}

Leaderboard::~Leaderboard() {
    delete[] scores; 
}

Leaderboard& Leaderboard::operator=(const Leaderboard& copyObj) {
    deepCopy(copyObj);

    return *this;
}

void Leaderboard::add(const GameEntry &entry) {
    const int addScore = entry.getScore();
    if (scoresLen == capacity) {
        if (scores[scoresLen - 1].getScore() > addScore) 
            return;
    } else ++scoresLen;
    
    int i = scoresLen - 1;

    while (i > 0 && scores[i - 1].getScore() < addScore) {
        scores[i] = scores[i - 1];
        --i;
    }
    
    scores[i] = entry;
}

void Leaderboard::removeWithName(const std::string name) {
    GameEntry removeItem(DEFAULT_SEARCH_SCORE, name);
    return remove(removeItem, MatchMode::Name);
}

void Leaderboard::removeWithScore(const int score) {
    GameEntry removeItem(score);
    return remove(removeItem, MatchMode::Score);
}

void Leaderboard::removeEntry(const GameEntry &entry) {;
    return remove(entry, MatchMode::Exact);
}

std::string Leaderboard::toString() const{
    std::string info = "#\t|\tname\t|\tscore\n";
    
    for (int i = 0; i < scoresLen; ++i)
        info += std::to_string(i + 1) + ")\t| " + scores[i].toString() + "\n";
    
    if (scoresLen == 0)
        info = "Leaderboard is empty!";

    return info;
}

GameEntry Leaderboard::findWithName(const std::string name) {
    GameEntry searchItem(DEFAULT_SEARCH_SCORE, name);
    return findEntry(searchItem, MatchMode::Name);
}

GameEntry Leaderboard::findWithScore(const int score) {
    GameEntry searchItem(score);
    return findEntry(searchItem, MatchMode::Score);
}

GameEntry Leaderboard::findEntry(const GameEntry &entry, const MatchMode matchMode /* = MatchMode::Exact*/) {
    GameEntry foundEntry = GameEntry(DEFAULT_SEARCH_SCORE, DEFAULT_SEARCH_NAME);

    auto foundIdx = getEntryIdx(entry, matchMode);

    if (foundIdx >= 0)
        foundEntry = scores[foundIdx];

    return foundEntry;
}

int Leaderboard::getEntryIdx(const GameEntry &searchEntry, const MatchMode& matchMode) {
    int foundIdx = -1;

    for (size_t i = 0; i < scoresLen; ++i) {
        bool foundFlag = true;
        bool isEqual;

        if (matchMode == MatchMode::Score or matchMode == MatchMode::Exact)
        {
            isEqual = scores[i].getScore() == searchEntry.getScore();
            foundFlag = foundFlag and isEqual;
        }
        if (matchMode == MatchMode::Name or matchMode == MatchMode::Exact)
        {
            isEqual = scores[i].getName().compare(searchEntry.getName()) == 0;
            foundFlag = foundFlag and isEqual;
        }

        if (foundFlag) {
            foundIdx = i;
            break;
        }
    }

    return foundIdx;
}

void Leaderboard::deepCopy(const Leaderboard& copyObj) {
    if (isInited) this->~Leaderboard();

    capacity = copyObj.capacity;
    scoresLen = copyObj.scoresLen;

    scores = new GameEntry[capacity];
    for (size_t i = 0; i < scoresLen; ++i)
        scores[i] = copyObj.scores[i];
}

void Leaderboard::remove(const GameEntry &entry, const MatchMode matchMode) {
    GameEntry foundEntry = GameEntry(DEFAULT_SEARCH_SCORE, DEFAULT_SEARCH_NAME);

    auto foundIdx = getEntryIdx(entry, matchMode);

    if (foundIdx < 0)
        return;

    removeAt(foundIdx);
}

void Leaderboard::removeAt(size_t idx) {
    if (idx >= capacity) throw "Index Out Of Bounds";

    for (size_t i = idx; i + 1 < scoresLen; ++i)
        scores[i] = scores[i + 1];

    --scoresLen;
}