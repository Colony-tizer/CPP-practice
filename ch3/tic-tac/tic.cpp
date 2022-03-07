#include "tic.h"
#include <iostream>

TicTac::TicTac() {
    board = new int*[BOARD_MAX_SIZE];
    for (int i = 0; i < BOARD_MAX_SIZE; ++i)
        board[i] = new int[BOARD_MAX_SIZE];
    clearBoard();
}

TicTac::~TicTac() {
    for (int i = 0; i < BOARD_MAX_SIZE; ++i) 
        delete[] board[i];
    delete[] board;
}

void TicTac::clearBoard() {
    for (int i = 0; i < BOARD_MAX_SIZE; ++i)
        for (int j = 0; j < BOARD_MAX_SIZE; ++j)
            board[i][j] = 0;
}

TicTac::Mark TicTac::checkWin() {
    const uint CHECK_ARR_SIZE =  2 * BOARD_MAX_SIZE + 1;
    auto res = TicTac::Mark::Toe;
    
    int *linesCheckArr = new int[CHECK_ARR_SIZE + 1];
    for (int i = 0; i < BOARD_MAX_SIZE; ++i) {
        for (int j = 0; j < BOARD_MAX_SIZE; ++j) {
            linesCheckArr[i] += board[i][j];
            linesCheckArr[BOARD_MAX_SIZE + j] += board[i][j];

            if (i == j) 
                linesCheckArr[CHECK_ARR_SIZE - 1] += board[i][j];

            if (j == BOARD_MAX_SIZE - i - 1) 
                linesCheckArr[CHECK_ARR_SIZE] += board[i][j];

            if (linesCheckArr[i] >= BOARD_MAX_SIZE || linesCheckArr[BOARD_MAX_SIZE + j] >= BOARD_MAX_SIZE 
            ||  linesCheckArr[CHECK_ARR_SIZE - 1] >= BOARD_MAX_SIZE || linesCheckArr[CHECK_ARR_SIZE] >= BOARD_MAX_SIZE)  
                res = TicTac::Mark::Tac;

            if (linesCheckArr[i] <= -BOARD_MAX_SIZE || linesCheckArr[BOARD_MAX_SIZE + j] <= -BOARD_MAX_SIZE 
            ||  linesCheckArr[CHECK_ARR_SIZE - 1] <= -BOARD_MAX_SIZE || linesCheckArr[CHECK_ARR_SIZE] <= -BOARD_MAX_SIZE)  
                res = TicTac::Mark::Tic;

            if (res != TicTac::Mark::Toe) 
                break;
        }
    }

    delete[] linesCheckArr;
    return res;
}

void TicTac::setCell(int i, int j, TicTac::Mark mark) {
    if (i >= 0 && i < TicTac::BOARD_MAX_SIZE 
     && j >= 0 && j < TicTac::BOARD_MAX_SIZE
     && board[i][j] == 0) 
        board[i][j] = (int)mark;
}

std::ostream& operator << (std::ostream &os, TicTac &obj) {
    char mark;
    for (int i = 0; i < TicTac::BOARD_MAX_SIZE; ++i) {
        os << " ";
        for (int j = 0; j < TicTac::BOARD_MAX_SIZE; ++j) {
            switch (obj.board[i][j]) {
                case (int)TicTac::Mark::Tic:
                    mark = 'X';
                    break;
                case (int)TicTac::Mark::Tac:
                    mark = 'O';
                    break;
                case (int)TicTac::Mark::Toe:
                    mark = ' ';
            }
            os << mark;
            if (j != TicTac::BOARD_MAX_SIZE - 1) os << " | ";
        }
        os << "\n";
    }
    return os;
}