#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

class Frog {
  public:
    Frog() {}
    Frog(int l, int w, int h):
      leap(l), weight(w), height(h) {}

    void setId(int i) { id = i; }

    bool operator<(Frog other) const {
      return weight < other.weight;
    }

    int id;
    int leap;
    int weight;
    int height;
};

int n;
unordered_map<string, int> m;

int numberThatCanJump(
  Frog* frogs,
  string used
){
  for (int i = 1; i <= n; i++) {
    cout << frogs[i].weight << '\n';
  }
  return 0;
}

int main() {
  int d;
  cin >> n >> d;
  string used(n + 1, '0');
  Frog frogs[n + 1];

  for (int i = 1; i <= n; i++) {
    int l, w, h;
    cin >> l >> w >> h;
    Frog f(l, w, h);
    frogs[i] = f;
  }

  sort(frogs, frogs + n);
  for (int i = 1; i <= n; i++) {
    frogs[i].setId(i);
  }

  int maxSoFar = 0;
  cout << numberThatCanJump(frogs, used) << endl;
}