#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int R, S, K, N;
  cin >> R >> S >> K;
  N = K - 2;

  char board[R][S];
  int globalSumBoard[R][S];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < S; j++) {
      char c;
      cin >> c;
      board[i][j] = c;
      int val = (c == '*');

      if (i == 0 || j == 0 || i == R - 1 || j == S - 1) {
        globalSumBoard[i][j] = 0;
      } else if (i == 1 && j == 1) {
        globalSumBoard[i][j] = val;
      } else if (i == 1) {
        globalSumBoard[i][j] = globalSumBoard[i][j - 1] + val;
      } else if (j == 1) {
        globalSumBoard[i][j] = globalSumBoard[i - 1][j] + val;
      } else {
        globalSumBoard[i][j] = val + globalSumBoard[i][j - 1] + globalSumBoard[i - 1][j] - globalSumBoard[i - 1][j - 1];
      }
    }
  }

  int max = 0;
  int topLeftX = 0;
  int topLeftY = 0;
  int bottomRightX = N + 1;
  int bottomRightY = N + 1;
  int sumBoard[R][S];

  for (int i = N; i < R; i++) {
    for (int j = N; j < S; j++) {
      if (i == 0 || j == 0 || i == R - 1 || j == S - 1) {
        sumBoard[i][j] = 0;
      } else if (i - N < 0 && j - N < 0) {
        sumBoard[i][j] = globalSumBoard[i][j];
        if (sumBoard[i][j] > max) {
          max = sumBoard[i][j];
          bottomRightX = i + 1;
          bottomRightY = j + 1;
        }
      } else if (i - N < 0) {
        sumBoard[i][j] = globalSumBoard[i][j] - globalSumBoard[i][j - N];
        if (sumBoard[i][j] > max) {
          max = sumBoard[i][j];
          bottomRightX = i + 1;
          bottomRightY = j + 1;
          topLeftY = j - N;
        }
      } else if (j - N < 0) {
        sumBoard[i][j] = globalSumBoard[i][j] - globalSumBoard[i - N][j];
        if (sumBoard[i][j] > max) {
          max = sumBoard[i][j];
          bottomRightX = i + 1;
          bottomRightY = j + 1;
          topLeftX = i - N;
        }
      } else {
        sumBoard[i][j] = globalSumBoard[i][j] - globalSumBoard[i][j - N] - globalSumBoard[i - N][j] + globalSumBoard[i - N][j - N];
        if (sumBoard[i][j] > max) {
          max = sumBoard[i][j];
          bottomRightX = i + 1;
          bottomRightY = j + 1;
          topLeftX = i - N;
          topLeftY = j - N;
        }
      }
    }
  }

  board[topLeftX][topLeftY] = '+';
  board[bottomRightX][topLeftY] = '+';
  board[topLeftX][bottomRightY] = '+';
  board[bottomRightX][bottomRightY] = '+';
  for (int i = topLeftX + 1; i < bottomRightX; i++) {
    board[i][topLeftY] = '|';
    board[i][bottomRightY] = '|';
  }
  for (int j = topLeftY + 1; j < bottomRightY; j++) {
    board[topLeftX][j] = '-';
    board[bottomRightX][j] = '-';
  }

  cout << max << '\n';
  
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < S; j++) {
      cout << board[i][j];
    }
    cout << '\n';
  }
}
