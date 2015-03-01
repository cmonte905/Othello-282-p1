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
   cout << "it is in bounds" << endl;
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

   int count = 0, player = (currentPlayer == 'B' ? 1 : -1);
   board[row][col] = player;
   PrintBoard(board);
   for (int i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
         cout << i << " <-- i - j -->" << j << endl;
         int checkR = row + i, checkC = col + j;
         cout << " Before the while loop" << endl;
         //&& InBounds(checkR, checkC)
         char check = board[checkR][checkC];
         cout << "Check what is in the 2d array " << check << endl;
         int c = 0;
         while (board[checkR][checkC] != 0 && InBounds(checkR, checkC)) {   //Checks to make sure that it is inbounds and if there is a 0, breaks if there is a 0
            cout << "Did it get in the while loop?\n" << endl;
            
            if (board[checkR][checkC] != player) { // keeps going until it reaches an friendly player
               cout << "Went into the first if statement" << endl;
               checkR += i; checkC += j;           // Keeps adding on these variables 
               count++;
               cout << i << " the I & count " << count << endl;//increments if there is a enemy piece 
            }
               cout << "Yes it did get inside" << endl;
            if (count > 0) {//If there were any pieces to move, then it would
               for (; count > 0; count--) { // SHould be going back to flip any pieces if there were any
                  cout << " Piece that should get swithced\n" << checkR << " " << checkC << endl;
                  checkC--; checkR--;
                  cout << checkC << checkR << endl;
                  board[checkR][checkC] = player;
                  cout << "---------------------------" << endl;
                  PrintBoard(board);
                  cout << "---------------------------" << endl;
                  cout << player << " <-- is player :Space that is getting switched" << checkR << checkC << endl;
               }

            }
            
            cout << "I fucking hate programming this shit, fuck the 20 line limit " << c << endl;
            c++;
            if (c == 5) {
               break;
            }
            break;
            cout << "Did it get out the while loop?" << endl;
            //cout << "Its doing something " << r << c<<  endl;
         }
         cout << " Comes out of the while loop" << endl;
      }

   }

   PrintBoard(board);
}

/*

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