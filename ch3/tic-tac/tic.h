#ifndef TIC_H_

#define TIC_H_

#include <ostream>


class TicTac {
    static const unsigned short BOARD_MAX_SIZE = 4;

    public:

        enum Mark {Tic = -1, Toe = 0, Tac = 1};

        TicTac();
        ~TicTac();
        void clearBoard();
        Mark checkWin();
        void setCell(int i, int j, Mark mark);
        friend std::ostream& operator<<(std::ostream &os, TicTac &obj);

    private:
        int **board;
};
#endif