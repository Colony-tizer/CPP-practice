#ifndef TIC_H_

#define TIC_H_

#include <ostream>

enum TicTacMark {Tic = -1, Toe = 0, Tac = 1};

class TicTac {
    static const unsigned short BOARD_MAX_SIZE = 4;

    public:
        TicTac();
        ~TicTac();
        void clearBoard();
        TicTacMark checkWin();
        void setCell(int i, int j, TicTacMark mark);
        friend std::ostream& operator<<(std::ostream &os, TicTac &obj);
    private:
        int **board;
};
#endif