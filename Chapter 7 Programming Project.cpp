//program that allows two players to play a game of tic-tac-toe
#include <array>
#include <iostream>
#include <string>
using namespace std;

//variables

const std::string player_1_token = "X";
const std::string player_2_token = "O";


//defining function prototypes

void initializeBoard(array<array<char, 3>, 3>& board);

void displayBoard(array<array<char, 3>, 3>& board);

void getLocation(int& row, int& col);

void placeToken(array<array<char, 3>, 3>& board, string playerToken);




int main()
{
    std::array<std::array<char, 3>, 3> board;
    initializeBoard(board);
    displayBoard(board);
    return 0;
}

void initializeBoard(array<array<char, 3>, 3>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            board[i][j] = '*';
        }
    }
}

void displayBoard(array<array<char, 3>, 3>& board) {
    std::cout << "    1  2  3\n";
    std::cout << "   ---------\n";

    for (int row = 0; row < 3; ++row) {
        std::cout << "|" << row + 1 << "| ";
        for (int col = 0; col < 3; ++col) {
            std::cout << board[row][col];
            if (col < 2) std::cout << "  ";
        }
        std::cout << "\n";
    }

}

void getLocation(int& row, int& col, array<array<char, 3>, 3>& board) {
    while (true) {
        std::cout << "Enter row (1-3): ";
        std::cin >> row;
        while (row < 1 || row > 3) {
            std::cout << "\nInvalid row, enter a value between 1 and 3: ";
            std::cin >> row;
        }
        std::cout << "\nEnter column (1-3): ";
        std::cin >> col;
        while (col < 1 || col > 3) {
            std::cout << "\nInvalid column, enter a value between 1 and 3: ";
            std::cin >> col;
        }
        //adjusting for the index starting at 0
        int rowIndex = row - 1;
        int colIndex = col - 1;
        
        if (board[rowIndex][colIndex] != '*') {
            std::cout << "Spot already filled, choose another.\n";
            continue; //loops again
        }
        //when valid location found
        break;
    } 
}
