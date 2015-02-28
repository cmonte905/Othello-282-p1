#include<iostream>
#include<stack>
#include"OthelloGame.h"
using namespace std;

void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
   cout << "- 0 1 2 3 4 5 6 7" << endl;
   for (int i = 0; i < BOARD_SIZE; i++) {
      cout << i;
      for (int j = 0; j < BOARD_SIZE; j++) {
         if (board[i][j] == 0) {
            cout << " .";
         }
         if (board[i][j] == 1) {
            cout << " B";
         }
         if (board[i][j] == -1) {
            cout << " W";
         }
      }
      cout << endl;
   }
}
bool InBounds(int row, int col) {
   return ((row < BOARD_SIZE) && (row >= -1)) && ((col < BOARD_SIZE) &&
      (col >= -1)) ? true : false;
}

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
   return (InBounds(row, col) && board[row][col] == 0) ? true : false;
}



void GetMove(int *row, int *col) {
   char temp;
   cin >> temp >> *row >> temp >> *col >> temp;
}

//switch with elvis cases
void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row
   , int col, char currentPlayer) {
   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         int r = row + i, c = col + j;
         int count = 0, player = (currentPlayer == 'B' ? 1 : -1);
         while (board[r][c] != 0 && InBounds(r, c)) {
            if (board[r][c] == (currentPlayer == 'B' ? -1 : 1)) {
               ();
               ();
            }
            if (board[r][c] == player && count > 0) {

            }
            else {
               false;
            }
         }
      }
   }
}

int GetValue(char board[BOARD_SIZE][BOARD_SIZE]) {
   for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
         int b = 0, w = 0, boardSize = 64;
         (board[i][j] == 1 ? b++ : w++);
         return (boardSize - w);
      }
   }
}
