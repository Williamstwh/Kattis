#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y, c;
  cin >> x >> y;
  int grid[x][y];
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cin >> c;
      if (i == 0 && j == 0) {
        grid[i][j] = c;
      } else if (i == 0) {
        grid[i][j] = c + grid[i][j - 1];
      } else if (j == 0) {
        grid[i][j] = c + grid[i - 1][j];
      } else {
        grid[i][j] = c + max(grid[i][j - 1], grid[i - 1][j]);
      }
    }
  }
  cout << grid[0][y - 1];
  for (int i = 1; i < x; i++) {
    cout << ' ' << grid[i][y - 1];
  }
  cout << '\n';
}