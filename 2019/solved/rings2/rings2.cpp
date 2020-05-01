#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getVal(
  vector< vector<char> > &characters,
  vector< vector<int> > &grid,
  vector< vector<bool> > &searched,
  int r,
  int c,
  int i,
  int j
) {
  if (i < 0 || i >= r || j < 0 || j >= r) {
    return 0;
  } else if (searched[i][j]) {
    return grid[i][j];
  } else if (characters[i][j] == '.') {
    searched[i][j] = true;
    grid[i][j] = 0;
    return 0;
  } else {
    searched[i][j] = true;
    grid[i][j] = 1 + min(
      min(
        getVal(characters, grid, searched, r, c, i - 1, j),
        getVal(characters, grid, searched, r, c, i + 1, j)
      ),
      min(
        getVal(characters, grid, searched, r, c, i, j - 1),
        getVal(characters, grid, searched, r, c, i, j + 1)
      )
    );
    return grid[i][j];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  char v;
  cin >> r >> c;
  vector< vector<char> > characters(r, vector<char>(c));
  vector< vector<int> > grid(r, vector<int>(c, INT32_MAX));
  vector< vector<bool> > searched(r, vector<bool>(c, false));

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> characters[i][j];
    }
  }

  int val;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      val = getVal(characters, grid, searched, r, c, i, j);
      cout << '.';
      if (val == 0) {
        cout << '.';
      } else {
        cout << val;
      }
    }
    cout << '\n';
  }
}