#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3] = { {'1', '2', '3'},
                     {'4', '5', '6'},
                     {'7', '8', '9'} };

int currentPlayer = 1;
char mark; 

void displayBoard() {
    system("cls");
    cout << " TIC TAC TOE \n";
    cout << " Player (X)  -  Computer (O) \n\n";

    for (int i = 0; i < 3; i++) {
        cout << "     |     |     \n";
        cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  \n";
        if (i < 2)
            cout << "_____|_____|_____\n";
    }
    cout << "     |     |     \n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = mark;
        return true;
    }
    return false;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    mark = (currentPlayer == 1) ? 'X' : 'O';
}

int getComputerMove() {
    srand(time(0));
    int move;
    do {
        move = rand() % 9 + 1;
    } while (!makeMove(move));
    return move;
}

int main() {
    int position;
    mark = 'X';

    while (true) {
        displayBoard();

        if (currentPlayer == 1) {  // Player's Turn
            cout << "Enter your move (1-9): ";
            cin >> position;

            if (position < 1 || position > 9 || !makeMove(position))
                continue;
        } else {  // Computer's Turn
            cout << "Computer is thinking...\n";
            position = getComputerMove();
        }

        if (checkWin()) {
            displayBoard();
            cout << (currentPlayer == 1 ? "You win!\n" : "Computer wins!\n");
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
