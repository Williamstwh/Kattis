#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
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

int numberThatCanJump(int frogIndex, int wellHeight, int weightLimit,
                      int numberOfFrogsSaved, int *maxSoFar) {
  if (frogIndex == 0 || weightLimit <= 0) {
    *maxSoFar = max(*maxSoFar, numberOfFrogsSaved);
    return numberOfFrogsSaved;
  } else if (wellHeight <= 0) {
    *maxSoFar = max(*maxSoFar, numberOfFrogsSaved);
    return frogIndex + numberOfFrogsSaved;
  } else if (frogIndex + numberOfFrogsSaved < *maxSoFar) {
    return INT_MIN;
  } else {
    // Get the heaviest frog
    Frog heaviest = frogs[frogIndex];
    int heaviestCanBeSaved = (heaviest.leap > wellHeight);
    vector<Frog> copy(frogs);
    // The heaviest frog used as a base
    int option1 = numberThatCanJump(frogIndex - 1,
                                    wellHeight - heaviest.height,
                                    min(weightLimit - heaviest.weight,
                                        heaviest.weight),
                                    numberOfFrogsSaved + heaviestCanBeSaved,
                                    maxSoFar);
    // The heaviest frog not used as a base
    int option2 = numberThatCanJump(frogIndex - 1,
                                    wellHeight,
                                    weightLimit,
                                    numberOfFrogsSaved + heaviestCanBeSaved,
                                    maxSoFar);
    return max(option1, option2);
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
  cout << numberThatCanJump(n, d, INT_MAX, 0, &maxSoFar) << endl;
}