#include "tic.h"
#include <iostream>

using namespace std;

int main() {
    TicTac t;
    cout<<"Welcome to T_T!"<<endl;
    cout<<t;
    t.setCell(1,1, TicTacMark::Tic);
    cout<<t;
    t.setCell(0,2, TicTacMark::Tac);
    cout<<t;
    t.setCell(0,0, TicTacMark::Tic);
    cout<<t;
    t.setCell(2,2, TicTacMark::Tac);
    cout<<t;
    t.setCell(2,1, TicTacMark::Tic);
    cout<<t;
    t.setCell(1,2, TicTacMark::Tac);
    cout<<t;
    t.setCell(3,1, TicTacMark::Tic);
    cout<<t;
    t.setCell(3,2, TicTacMark::Tac);
    cout<<t;
    cout<<"won: "<<t.checkWin()<<endl;
}