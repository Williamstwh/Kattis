#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

class Frog {
  public:
    Frog(int l, int w, int h):
    leap(l), weight(w), height(h) {}

    bool operator<(Frog other) const {
      return weight < other.weight;
    }

    int leap;
    int weight;
    int height;
};

vector<Frog> frogs;
unordered_map<string, int> map;
int maxSoFar;

int numberThatCanJump(int frogIndex, int wellHeight, int weightLimit) {
  if (frogIndex == 0 || weightLimit <= 0) {
    return 0;
  } else if (frogIndex < maxSoFar) {
    return 0;
  } {
    int result;
    string s = to_string(frogIndex) + ":" + to_string(wellHeight) + ":" + to_string(weightLimit);
    if (map.find(s) != map.end()) {
      return map[s];
    } else if (wellHeight <= 0) {
      result = frogIndex;
    } else {
      // Get the heaviest frog
      Frog heaviest = frogs[frogIndex];
      int heaviestCanBeSaved = (heaviest.leap > wellHeight);
      // The heaviest frog used as a base
      int option1 = numberThatCanJump(frogIndex - 1,
                                      wellHeight - heaviest.height,
                                      min(weightLimit - heaviest.weight,
                                          heaviest.weight));
      // The heaviest frog not used as a base
      int option2 = numberThatCanJump(frogIndex - 1,
                                      wellHeight,
                                      weightLimit);
      result = heaviestCanBeSaved + max(option1, option2);
    }
    map[s] = result;
    maxSoFar = max(maxSoFar, result);
    return result;
  }
}

int main() {
  int n, d;
  cin >> n >> d;
  Frog df(0, 0, 0);
  frogs.push_back(df);

  for (int i = 0; i < n; i++) {
    int l, w, h;
    cin >> l >> w >> h;
    Frog f(l, w, h);
    frogs.push_back(f);
  }

  sort(frogs.begin(), frogs.end());

  int maxSoFar = 0;
  cout << numberThatCanJump(n, d, INT32_MAX) << endl;
}