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
   return (row < BOARD_SIZE) && (row >= 0) && (col < BOARD_SIZE) && (col >= 0);
}

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
   return (InBounds(row, col) && board[row][col] == 0);
}

void GetMove(int *row, int *col) {
   char temp;
   cin >> *row >> temp >> *col; // easier for testing, get rid of when done 
   //cin >> temp >> *row >> temp >> *col >> temp;
}


//switch with elvis cases
void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row,
   int col, char currentPlayer) {

   bool moreThanOne = true;
   int count = 0, current = (currentPlayer == 'B' ? 1 : -1);
   int opposite = (currentPlayer == 'B' ? -1 : 1);
   cout << "Currently in applyMove " << current << endl;
   board[row][col] = current;
   for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
         int checkR = row + i, checkC = col + j;
         while (board[checkR][checkC] == opposite) {
            checkR += i; checkC += j;
            count++;
            if (board[checkR][checkC] == current && InBounds(checkR, checkC)) {   //&& InBounds(checkR, checkC)
               break;
            }
         }


         if (board[checkR][checkC] == current) {
            for (;;) {
               cout << " Piece that should get swithced " << checkR << " " << checkC << endl;
               for (; count > -1; count--) {
                  checkR -= i; checkC -= j;
                  board[checkR][checkC] = current;
               }
               if (board[checkR][checkC] == board[row][col]) {
                  break;
               }
            }
         }

      }

      //PrintBoard(board);
   }
}

/*

cout << "I fucking hate programming this shit, fuck the 20 line limit " << c << endl;
c++;
if (c == 5) {
break;
}
break;



else {//If there were any pieces to move, then it would
if (count > 0) {
for (; count > 0; count--) { // SHould be going back to flip any pieces if there were any
cout << " Piece that should get swithced" << checkR << " " << checkC << endl;
checkR -= i; checkC -= j;
board[checkR][checkC] = current;
cout << "---------------------------" << endl;
PrintBoard(board);
cout << "---------------------------" << endl;
}
}
}

void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row
, int col, char currentPlayer) {
//stack<char*> dir;
int player = ((currentPlayer == 'B') ? 1 : -1);
for (int r = -1; r <= 1; r++) { //check every direction
for (int c = -1; c <= 1; c++) {
int bRow = row + r, bCol = col + c, count = 0;; //go in that direction
while (InBounds(bRow, bCol) && (board[bRow][bCol] != 0)) { //while valid (in bound and not empty)
if (board[bRow][bCol] != player) //true if that room contain enemy
count++;
else { //room contain player
if (count > 0) {
for (; count > 0; count--) {
bRow--, bCol--;
board[bRow][bCol] = player;
}
break;
}
}
bRow += r, bCol += c;
}

}
}
}
void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char currentPlayer) {
int changeRow, changeCol, i, j = 0;
char opposingPlayer = (currentPlayer == 'B') ? 1 : -1;
board[row][col] = currentPlayer;
for (changeRow = -1; changeRow < 2; changeRow++)
for (changeCol = -1; changeCol < 2; changeCol++) {

if (board[row + changeRow][col + changeCol] == opposingPlayer) {
i = row + changeRow;
j = col + changeCol;
for (;;) {
i += changeRow;
j += changeCol;
if (!(InBounds(i, j)))
break;
if (board[i][j] == 0)
break;
if (board[i][j] == currentPlayer) {
while (board[i -= changeRow][j -= changeCol] == opposingPlayer)
board[i][j] = currentPlayer;
break;
}
}
}
}
}






int GetValue(char board[BOARD_SIZE][BOARD_SIZE]) {
for (int i = 0; i < BOARD_SIZE; i++) {
for (int j = 0; j < BOARD_SIZE; j++) {
int b = 0, w = 0, sum = 0;
(board[i][j] == 1 ? b++ : w++);
return (sum = b);
}
}
}
*/