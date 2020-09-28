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
int *height;
int *weight;
unordered_map<string, int> map;
int maxSoFar;

int numberThatCanJump(int frogIndex, int wellHeight, int weightLimit, int jumpedSoFar) {
  // If there are no frogs left
  if (frogIndex == 0) {
    // Set maxSoFar to the max of maxSoFar and jumpedSoFar
    maxSoFar = max(maxSoFar, jumpedSoFar);
    return jumpedSoFar;
  // If the total number of frogs that can pass if less than the max so far
  } else if (jumpedSoFar + frogIndex < maxSoFar) {
    return INT32_MIN;
  // If the wellHeight is greater than ones we've seen before and the weightLimit is lower
  } else if (wellHeight == height[frogIndex] && weightLimit == weight[frogIndex]) {
    return map[to_string(frogIndex) + ":" + to_string(wellHeight) + ":" + to_string(weightLimit)];
  } else if (wellHeight >= height[frogIndex] && weightLimit <= weight[frogIndex]) {
    return INT32_MIN;
  } else {
    Frog frog = frogs[frogIndex];
    int newJumpedSoFar = jumpedSoFar + (frog.leap > wellHeight);
    int maxNumberJumped = max(
      numberThatCanJump(frogIndex - 1, wellHeight, weightLimit, newJumpedSoFar),
      numberThatCanJump(
        frogIndex - 1,
        wellHeight - frog.height,
        min(frog.weight, weightLimit - frog.weight),
        newJumpedSoFar)
    );
    if (wellHeight <= height[frogIndex] && weightLimit >= weight[frogIndex]) {
      height[frogIndex] = wellHeight;
      weight[frogIndex] = weightLimit;
    }
    maxSoFar = max(maxSoFar, maxNumberJumped);
    map[to_string(frogIndex) + ":" + to_string(wellHeight) + ":" + to_string(weightLimit)] = maxNumberJumped;
    return maxNumberJumped;
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
  height = new int[n + 1];
  weight = new int[n + 1];
  fill_n(height, n + 1, INT32_MAX);
  fill_n(weight, n + 1, INT32_MIN);
  cout << numberThatCanJump(n, d, INT32_MAX, 0) << endl;
}