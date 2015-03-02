#include <iostream>
#include "OthelloGame.h"
using namespace std;

int main() {
   bool gameState = true;
   char board[BOARD_SIZE][BOARD_SIZE], move;
   int row, col, turn = 0, skip = 0;
   for (int row = 0; row < BOARD_SIZE; row++) {
      for (int col = 0; col < BOARD_SIZE; col++) {
         board[row][col] = 0;
      }
   }
   cout << "Welcome to Othello" << endl;
   board[3][4] = 1;
   board[4][4] = -1;
   board[4][3] = 1;
   board[3][3] = -1;
   PrintBoard(board);
   while (gameState) {
      if (turn % 2 == 0) {
         cout << "Black players turn, enter a move" << endl;
      }
      else {
         cout << "White players turn, enter a move" << endl;
      }
      GetMove(&row, &col);
      while (!(IsValidMove(board, row, col))) {
         cout << "Move is invalid, please enter a valid move" << endl;
         GetMove(&row, &col);
      }
      char playerTurn = (turn % 2 == 0 ? 'B' : 'W');
      ApplyMove(board, row, col, playerTurn);
      turn++;
      if (row == -1 && col == -1) {
         skip++;
         cout << "Have skipped your turn" << endl;
         if (skip == 2)
            break;
      }
      else {
         skip = 0;
         PrintBoard(board);
      }
   }
   int tempWin = GetValue(board);
   if (tempWin > 0) {
      cout << "Black wins " << endl;
   }
   else if (tempWin < 0) {
      cout << "White wins" << endl;
   }
   else {
      cout << "It is a tie" << endl;
   }
   system("pause");
   return 0;
}
