#include <iostream>
#include <vector>
#include <limits> 
#include <iomanip> 

using namespace std;


const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';


const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string RESET = "\033[0m";

void clearScreen() {
    cout << "\033[2J\033[1;1H"; // 
}

void printBoard(const vector<vector<char>>& board) {
    clearScreen();
    cout << BLUE << "  C O N N E C T   F O U R\n" << RESET;
    cout << "-----------------------------\n";
    
    for (int i = 0; i < ROWS; ++i) {
        cout << "|";
        for (int j = 0; j < COLS; ++j) {
            char piece = board[i][j];
            string color = (piece == PLAYER1) ? RED : 
                          (piece == PLAYER2) ? YELLOW : "";
            cout << " " << color << piece << RESET << " |";
        }
        cout << "\n";
    }
    cout << "-----------------------------\n";
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    cout << "-----------------------------\n";
}

bool isValidMove(const vector<vector<char>>& board, int col) {
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

void makeMove(vector<vector<char>>& board, int col, char player) {
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            break;
        }
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && 
                board[i][j+1] == player && 
                board[i][j+2] == player && 
                board[i][j+3] == player) {
                return true;
            }
        }
    }

    
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == player && 
                board[i+1][j] == player && 
                board[i+2][j] == player && 
                board[i+3][j] == player) {
                return true;
            }
        }
    }

    
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (board[i][j] == player && 
                board[i+1][j+1] == player && 
                board[i+2][j+2] == player && 
                board[i+3][j+3] == player) {
                return true;
            }
        }
    }

    
    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 3; j < COLS; ++j) {
            if (board[i][j] == player && 
                board[i+1][j-1] == player && 
                board[i+2][j-2] == player && 
                board[i+3][j-3] == player) {
                return true;
            }
        }
    }

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int j = 0; j < COLS; ++j) {
        if (board[0][j] == EMPTY) {
            return false;
        }
    }
    return true;
}

int getValidInput() {
    int col;
    while (true) {
        cout << "Enter column (1-7): ";
        cin >> col;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        } else if (col < 1 || col > 7) {
            cout << "Column must be between 1 and 7.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return col - 1;
        }
    }
}

int main() {
    vector<vector<char>> board(ROWS, vector<char>(COLS, EMPTY));
    bool player1Turn = true;
    bool gameOver = false;

    cout << BLUE << "  W E L C O M E   T O\n";
    cout << "  C O N N E C T   F O U R\n" << RESET;
    cout << "Player 1: " << RED << PLAYER1 << RESET << "  Player 2: " << YELLOW << PLAYER2 << RESET << "\n\n";
    cout << "Press Enter to start...";
    cin.ignore();

    while (!gameOver) {
        printBoard(board);
        
        char currentPlayer = player1Turn ? PLAYER1 : PLAYER2;
        string color = player1Turn ? RED : YELLOW;
        
        cout << color << "Player " << currentPlayer << "'s turn" << RESET << "\n";
        int col = getValidInput();

        if (!isValidMove(board, col)) {
            cout << "Column is full. Please choose another column.\n";
            continue;
        }

        makeMove(board, col, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << color << "\nPLAYER " << currentPlayer << " WINS!\n" << RESET;
            gameOver = true;
        } else if (isBoardFull(board)) {
            printBoard(board);
            cout << "\nGAME ENDED IN A DRAW!\n";
            gameOver = true;
        } else {
            player1Turn = !player1Turn;
        }
    }

    cout << "\nThanks for playing!\n";
    return 0;
}