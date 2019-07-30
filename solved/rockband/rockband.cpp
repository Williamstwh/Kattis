#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int X, Y;
  cin >> X >> Y;
  int grid[X][Y];
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
      cin >> grid[i][j];
    }
  }

  set<int> s;
  for (int j = 0; j < Y; j++) {
    for (int i = 0; i < X; i++) {
      s.insert(grid[i][j]);
    }
    if (s.size() == j + 1) {
      break;
    }
  }

  cout << s.size() << '\n';
  set<int>::iterator it = s.begin();
  cout << (*it);
  it++;
  while (it != s.end()) {
    cout << ' ' << (*it);
    it++;
  }
  cout << '\n';
}