#include <iostream>
#include <vector>
using namespace std;

void rotateClockwise(vector< vector <int> > &grid) {
  int a, b, c, d;
  a = grid[0][0];
  grid[0][0] = grid[3][0];
  grid[3][0] = grid[3][3];
  grid[3][3] = grid[0][3];
  grid[0][3] = a;

  b = grid[0][1];
  grid[0][1] = grid[2][0];
  grid[2][0] = grid[3][2];
  grid[3][2] = grid[1][3];
  grid[1][3] = b;

  c = grid[1][0];
  grid[1][0] = grid[3][1];
  grid[3][1] = grid[2][3];
  grid[2][3] = grid[0][2];
  grid[0][2] = c;

  d = grid[1][1];
  grid[1][1] = grid[2][1];
  grid[2][1] = grid[2][2];
  grid[2][2] = grid[1][2];
  grid[1][2] = d;
}

void rotateAntiClockwise(vector< vector <int> > &grid) {
  rotateClockwise(grid);
  rotateClockwise(grid);
  rotateClockwise(grid);
}

void flushRowLeft(vector<int> &row) {
  vector<int> temp = row;
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (temp[i] != 0) {
      row[count] = temp[i];
      count++;
    }
  }
  for (int i = count; i < 4; i++) {
    row[i] = 0;
  }
  for (int i = 0; i < 3; i++) {
    if (row[i] == row[i + 1]) {
      row[i] *= 2;
      for (int j = i + 1; j < 3; j++) {
        row[j] = row[j + 1];
      }
      row[3] = 0;
    }
  }
}

void flushLeft(vector< vector<int> > &grid) {
  for (int r = 0; r < 4; r++) {
    flushRowLeft(grid[r]);
  }
}

int main() {
  vector< vector<int> > grid(4, vector<int>(4));
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      cin >> grid[r][c];
    }
  }
  int dir;
  cin >> dir;
  if (dir == 0) {
    flushLeft(grid);
  } else if (dir == 1) {
    rotateAntiClockwise(grid);
    flushLeft(grid);
    rotateClockwise(grid);
  } else if (dir == 2) {
    rotateClockwise(grid);
    rotateClockwise(grid);
    flushLeft(grid);
    rotateClockwise(grid);
    rotateClockwise(grid);
  } else {
    rotateClockwise(grid);
    flushLeft(grid);
    rotateAntiClockwise(grid);
  }
  
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      cout << grid[r][c];
      if (c != 3) {
        cout << ' ';
      }
    }
    cout << endl;
  }
}