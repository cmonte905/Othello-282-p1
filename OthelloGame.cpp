#include<iostream>
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
      (col >= -1  )) ? true : false;
}
/*
bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {

}

void GetMove(int *row, int *col) {

}

void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col,
char currentPlayer) {

}

int GetValue(char board[BOARD_SIZE][BOARD_SIZE]) {

}

*/

