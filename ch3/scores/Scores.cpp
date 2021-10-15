#include "Scores.h"

Scores::Scores(int cap) {
    capacity = cap;
    if (cap < 0) capacity = 10;
    scoresLen = 0;
    scores = new GameEntry[cap];
}

Scores::~Scores() {
    delete[] scores; 
}

void Scores::add(const GameEntry &entry) {
    const int addScore = entry.getScore();
    if (scoresLen == capacity) {
        if (scores[scoresLen - 1].getScore() > addScore) 
            return;
    } else ++scoresLen;
    
    int i = scoresLen - 1;

    while (i > 0 && scores[i-1].getScore() < addScore) {
        scores[i] = scores[i-1];
        --i;
    }
    
    scores[i] = entry;
}

GameEntry Scores::remove(const GameEntry &entry, CheckMode mode) {
    GameEntry rem = GameEntry(INT32_MIN, "NO_MATCH");
    for (int cnt = 0; cnt < scoresLen; ++cnt) {
        bool flag = true;
        if (mode == CheckMode::ScoreCheck || mode == CheckMode::BothCheck) flag = flag && scores[cnt].getScore() == entry.getScore();
        if (mode == CheckMode::NameCheck  || mode == CheckMode::BothCheck) flag = flag && scores[cnt].getName() == entry.getName();
        if (flag) {
            rem = removeAt(cnt);
            break;
        }
    }
    return rem;
}

GameEntry Scores::remove(const GameEntry &entry) {
    return remove(entry, CheckMode::BothCheck);
}

GameEntry Scores::remove(int score) {
    return remove(GameEntry(score), CheckMode::ScoreCheck);
}

GameEntry Scores::removeAt(int index) {
    GameEntry removed = GameEntry(scores[index]);
    int cnt = index;

    for (; cnt + 1 < scoresLen; ++cnt) {
        scores[cnt] = scores[cnt+1];
    }

    scores[cnt] = GameEntry();
    --scoresLen;

    return removed;
}
string Scores::toString() const{
    string info = "place |    name    |     score\n";
    for (int i = 0; i < scoresLen; ++i)
        info += to_string(i+1) + "| " + scores[i].toString() + "\n";
    return info;
}