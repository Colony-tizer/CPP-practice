#include "tic.h"
#include <iostream>

using namespace std;

int main() {
    TicTac t;

    cout << "Welcome to Tic_Tac Game Demo!" << endl;
    cout << "Tic is: " << TicTac::Mark::Tic << " Tac is " << TicTac::Mark::Tac << endl;

    cout << t;

    t.setCell(1,1, TicTac::Mark::Tic);
    cout << t;

    t.setCell(0,2, TicTac::Mark::Tac);
    cout << t;

    t.setCell(0,0, TicTac::Mark::Tic);
    cout << t;

    t.setCell(2,2, TicTac::Mark::Tac);
    cout << t;

    t.setCell(2,1, TicTac::Mark::Tic);
    cout << t;

    t.setCell(1,2, TicTac::Mark::Tac);
    cout << t;

    t.setCell(3,1, TicTac::Mark::Tic);
    cout << t;

    t.setCell(3,2, TicTac::Mark::Tac);
    cout << t;

    cout << "Won: " << t.checkWin() << endl;
}