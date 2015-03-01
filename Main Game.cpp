#include <iostream>
#include "OthelloGame.h"
using namespace std;

int main() {
   bool gameState = true;
   char board[BOARD_SIZE][BOARD_SIZE];
   int row, col, turn = 0;
   for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE; col++) {
         board[row][col] = 0;
      }
   }
   cout << "Welcome to Othello" << endl;
   board[3][4] = 1; board[4][4] = -1;
   board[4][3] = 1; board[3][3] = -1;
   PrintBoard(board);
   while (gameState) {
      cout << "Black players turn, enter a move" << endl;
      GetMove(&row, &col);
      if (InBounds(row, col)) {
         ApplyMove(board, row, col, 'B');
      }
      else {
         cout << "Move is invalid, please enter a valid move" << endl;
         GetMove(&row, &col);         
      }
     // PrintBoard(board);
      cout << "White players turn, enter a move" << endl;
      GetMove(&row, &col);
      if (InBounds(row, col)) {
         ApplyMove(board, row, col, 'W');
         PrintBoard(board);
      }
      else {
         cout << "Move is invalid, please enter a valid move" << endl;
         GetMove(&row, &col);
      }
   }
   //GetValue(board);
   system("pause");
   return 0;
}