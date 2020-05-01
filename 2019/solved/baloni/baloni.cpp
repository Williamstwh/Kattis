#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_map<int, int> arrows;

  int n;
  cin >> n;
  int dropped = 0;

  int p;
  while (n--) {
    cin >> p;
    // Remove all arrows with the current height
    arrows[p] = arrows[p] > 0 ? arrows[p] - 1 : arrows[p];
    if (!arrows[p]) {
      arrows.erase(p);
    }

    // Add to all arrows with height - 1
    arrows[p - 1]++;
  }
  for (auto pair: arrows) {
    dropped += pair.second;
  }
  cout << dropped << "\n";
}