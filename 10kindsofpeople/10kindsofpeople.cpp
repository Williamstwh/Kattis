#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
vector< vector<T> > genericGrid(int r, int c, T initValue) {
  vector< vector<T> > emptyMap(r, vector<T>(c));
  for (int row = 0; row < r; row++) {
    for (int col = 0; col < c; col++) {
      emptyMap[row][col] = initValue;
    }
  }
  return emptyMap;
}

void fill(vector< vector<int> > &map,
          vector< vector<bool> > &hasVisited,
          vector< vector<int> > &islands,
          int island, int value, int rows, int cols, int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols ||
      hasVisited[row][col] || map[row][col] != value) {
    return;
  }
  hasVisited[row][col] = true;
  islands[row][col] = island;
  fill(map, hasVisited, islands, island, value, rows, cols, row + 1, col);
  fill(map, hasVisited, islands, island, value, rows, cols, row - 1, col);
  fill(map, hasVisited, islands, island, value, rows, cols, row, col + 1);
  fill(map, hasVisited, islands, island, value, rows, cols, row, col - 1);
}

template <class T>
void printGrid(vector< vector<T> > grid, int r, int c) {
  for (int row = 0; row < r; row++) {
    for (int col = 0; col < c; col++) {
      cout << grid[row][col];
    }
    cout << endl;
  }
}

int main() {
  // Read Inputs and Declare Data Structures
  int rows, cols;
  cin >> rows >> cols;

  vector< vector<int> > map(rows, vector<int>(cols));
  vector< vector<bool> > hasVisited = genericGrid(rows, cols, false);
  vector< vector<int> > islands = genericGrid(rows, cols, 0);

  string line;
  for (int row = 0; row < rows; row++) {
    cin >> line;
    for (int col = 0; col < cols; col++) {
      map[row][col] = line.at(col) - 48;
    }
  }

  int island = 1;

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      if (!hasVisited[row][col]) {
        fill(map, hasVisited, islands, island, map[row][col], rows, cols, row, col);
        island++;
      }
    }
  }

  int n;
  cin >> n;

  int sr, sc, er, ec;
  for (int t = 0; t < n; t++) {
    cin >> sr >> sc >> er >> ec;
    sr--; sc--; er--; ec--;
    if (islands[sr][sc] == islands[er][ec]) {
      if (map[sr][sc] == 1) {
        cout << "decimal" << endl;
      } else {
        cout << "binary" << endl;
      }
    } else {
      cout << "neither" << endl;
    }
  }
}
