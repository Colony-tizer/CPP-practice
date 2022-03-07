#include "Leaderboard.h"

Leaderboard::Leaderboard(int cap /* = 10*/) {
    capacity = cap;
    if (cap < 0) capacity = 10;

    scoresLen = 0;
    scores = new GameEntry[cap];
}

Leaderboard::~Leaderboard() {
    delete[] scores; 
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

GameEntry Leaderboard::remove(const GameEntry &entry) {
    return remove(entry, CheckMode::BothCheck);
}

GameEntry Leaderboard::remove(int score) {
    return remove(GameEntry(score), CheckMode::ScoreCheck);
}

std::string Leaderboard::toString() const{
    std::string info = "#\t|\tname\t|\tscore\n";
    
    for (int i = 0; i < scoresLen; ++i)
        info += std::to_string(i + 1) + ")\t| " + scores[i].toString() + "\n";
    
    if (scoresLen == 0)
        info = "Leaderboard is empty!";

    return info;
}

GameEntry Leaderboard::remove(const GameEntry &entry, CheckMode mode) {
    GameEntry rem = GameEntry(INT32_MIN, "NO_MATCH");
    for (int cnt = 0; cnt < scoresLen; ++cnt) {
        bool flag = true;
        if (mode == CheckMode::ScoreCheck || mode == CheckMode::BothCheck) 
            flag = flag && scores[cnt].getScore() == entry.getScore();
        
        if (mode == CheckMode::NameCheck  || mode == CheckMode::BothCheck) 
            flag = flag && scores[cnt].getName() == entry.getName();
        
        if (flag) {
            rem = removeAt(cnt);
            break;
        }
    }
    return rem;
}

GameEntry Leaderboard::removeAt(int idx) {
    GameEntry removed = GameEntry(scores[idx]);
    int cnt = idx;

    for (; cnt + 1 < scoresLen; ++cnt) {
        scores[cnt] = scores[cnt + 1];
    }

    scores[cnt] = GameEntry();
    --scoresLen;

    return removed;
}