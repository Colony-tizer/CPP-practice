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
TicTacMark TicTac::checkWin() {
    TicTacMark res = TicTacMark::Toe;
    int *linesCheck = new int[2*BOARD_MAX_SIZE + 2];
    for (int i = 0; i < BOARD_MAX_SIZE; ++i) {
        for (int j = 0; j < BOARD_MAX_SIZE; ++j) {
            linesCheck[i] += board[i][j];
            linesCheck[BOARD_MAX_SIZE + j] += board[i][j];
            if (i==j) linesCheck[2*BOARD_MAX_SIZE] += board[i][j];
            if (j==BOARD_MAX_SIZE-i-1) linesCheck[2*BOARD_MAX_SIZE+1] += board[i][j];
            if (linesCheck[i] >= BOARD_MAX_SIZE || linesCheck[BOARD_MAX_SIZE + j] >= BOARD_MAX_SIZE 
            ||  linesCheck[2*BOARD_MAX_SIZE] >= BOARD_MAX_SIZE || linesCheck[2*BOARD_MAX_SIZE+1] >= BOARD_MAX_SIZE)  
                res = TicTacMark::Tac;
            if (linesCheck[i] <= -BOARD_MAX_SIZE || linesCheck[BOARD_MAX_SIZE + j] <= -BOARD_MAX_SIZE 
            ||  linesCheck[2*BOARD_MAX_SIZE] <= -BOARD_MAX_SIZE || linesCheck[2*BOARD_MAX_SIZE+1] <= -BOARD_MAX_SIZE)  
                res = TicTacMark::Tic;
            if (res != TicTacMark::Toe) 
                break;
        }
    }/*
    for (int i = 0; i < 2*BOARD_MAX_SIZE+2; ++i) {
        std::cout<<std::endl<<linesCheck[i]<<std::endl<<std::endl;
    }*/
    delete[] linesCheck;
    return res;
}
std::ostream& operator<<(std::ostream &os, TicTac &obj) {
    os<<TicTac::BOARD_MAX_SIZE<<"\n";
    char mark;
    for (int i = 0; i < TicTac::BOARD_MAX_SIZE; ++i) {
        os<<" ";
        for (int j = 0; j < TicTac::BOARD_MAX_SIZE; ++j) {
            switch (obj.board[i][j]) {
                case (int)TicTacMark::Tic:
                    mark = 'X';
                    break;
                case (int)TicTacMark::Tac:
                    mark = 'O';
                    break;
                case (int)TicTacMark::Toe:
                    mark = ' ';
            }
            os<<mark;
            if (j != TicTac::BOARD_MAX_SIZE - 1) os<<" | ";
        }
        os<<"\n";
    }
    return os;
}
void TicTac::setCell(int i, int j, TicTacMark mark) {
    if (i >= 0 && i < TicTac::BOARD_MAX_SIZE 
     && j >= 0 && j < TicTac::BOARD_MAX_SIZE
     && board[i][j] == 0) 
        board[i][j] = (int)mark;
}