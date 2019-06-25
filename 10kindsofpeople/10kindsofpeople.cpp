#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector< vector<bool> > emptyBoolMap(int r, int c) {
  vector< vector<bool> > emptyMap(r, vector<bool>(c));
  for (int row = 0; row < r; row++) {
    for (int col = 0; col < c; col++) {
      emptyMap[row][col] = false;
    }
  }
  return emptyMap;
}

int main() {
  int r, c;
  cin >> r >> c;

  vector< vector<int> > map(r, vector<int>(c));

  string line;
  for (int row = 0; row < r; row++) {
    cin >> line;
    for (int col = 0; col < c; col++) {
      map[row][col] = line.at(col) - 48;
    }
  }

  int n;
  cin >> n;

  int sr, sc, er, ec;
  for (int t = 0; t < n; t++) {
    cin >> sr >> sc >> er >> ec;
    sr--; sc--; er--; ec--;
    int startType = map[sr][sc];

    if (canTravel(map, emptyBoolMap(r, c),
        r, c, sr, sc, er, ec, startType)) {
      if (startType == 1) {
        cout << "decimal" << endl;
      } else {
        cout << "binary" << endl;
      }
    } else {
      cout << "neither" << endl;
    }
  }
}
