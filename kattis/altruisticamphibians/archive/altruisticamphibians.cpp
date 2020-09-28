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

int numberThatCanJump(vector<Frog> frogs, int wellHeight, int weightLimit,
                      int numberOfFrogsSaved, int *maxSoFar) {
  int numOfFrogs = frogs.size();
  if (numOfFrogs == 0 || weightLimit <= 0) {
    *maxSoFar = max(*maxSoFar, numberOfFrogsSaved);
    return numberOfFrogsSaved;
  } else if (wellHeight <= 0) {
    *maxSoFar = max(*maxSoFar, numberOfFrogsSaved);
    return numOfFrogs + numberOfFrogsSaved;
  } else if (frogs.size() + numberOfFrogsSaved < *maxSoFar) {
    return INT_MIN;
  } else {
    // Get the heaviest frog
    Frog heaviest = frogs.back();
    frogs.pop_back();
    int heaviestCanBeSaved = (heaviest.leap > wellHeight);
    vector<Frog> copy(frogs);
    // The heaviest frog used as a base
    int option1 = numberThatCanJump(frogs,
                                    wellHeight - heaviest.height,
                                    min(weightLimit - heaviest.weight,
                                        heaviest.weight),
                                    numberOfFrogsSaved + heaviestCanBeSaved,
                                    maxSoFar);
    // The heaviest frog not used as a base
    int option2 = numberThatCanJump(copy,
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
  vector<Frog> frogs;

  for (int i = 0; i < n; i++) {
    int l, w, h;
    cin >> l >> w >> h;
    Frog f(l, w, h);
    frogs.push_back(f);
  }

  sort(frogs.begin(), frogs.end());

  int maxSoFar = 0;
  cout << numberThatCanJump(frogs, d, INT_MAX, 0, &maxSoFar) << endl;
}