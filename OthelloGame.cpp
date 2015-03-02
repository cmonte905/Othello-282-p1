#include<iostream>
#include<stack>
#include"OthelloGame.h"
using namespace std;

void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
   cout << "- 0 1 2 3 4 5 6 7 " << endl;
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
   return (row < BOARD_SIZE) && (row > -1) && (col < BOARD_SIZE) && (col > -1);
}

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
   return (InBounds(row, col) && (board[row][col] == 0)) ||
      ((row == -1 && col == -1));
}

void GetMove(int *row, int *col) {
   char temp;
   cin >> temp >> *row >> temp >> *col >> temp;
}


void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row,
   int col, char currentPlayer) {
   int count = 0, current = (currentPlayer == 'B' ? 1 : -1);
   int opposite = (currentPlayer == 'B' ? -1 : 1);
   board[row][col] = current;
   for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
         int cRow = row + i, cCol = col + j;
         count = 0;
         while (board[cRow][cCol] == opposite && InBounds(cRow, cCol)) {
            cRow += i; cCol += j;
            count++;
            if (board[cRow][cCol] == current) {
               break;
            }
         }
         if (board[cRow][cCol] == current) {
            for (;;) {
               for (; count >= 0; count--) {
                  cRow -= i; cCol -= j;
                  board[cRow][cCol] = current;
               }
               if (board[cRow][cCol] == board[row][col]) {
                  break;
               }
            }
         }
      }
   }
}

int GetValue(char board[BOARD_SIZE][BOARD_SIZE]) {
   int sum = 0;
   for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
         sum += board[i][j];
      }
   }
   return sum;
}

