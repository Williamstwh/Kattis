#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int main() {
  ull N, X;
  cin >> N >> X;
  ull max = (N - 2) * (N - 1) / 2;
  vector<int> inside;
  vector<int> outside;

  if (X > max) {
    cout << -1 << '\n';
  } else {
    for (ull h = 1; h <= N - 2; h++) {
      ull v = N - 1 - h;
      if (X >= v) {
        X -= v;
        inside.push_back(h);
      } else {
        outside.push_back(h);
      }
    }
    cout << N - 1;
    int l = inside.size();
    while (l--) {
      cout << ' ' << inside.back();
      inside.pop_back();
    }
    cout << ' ' << N;
    l = outside.size();
    while (l--) {
      cout << ' ' << outside.back();
      outside.pop_back();
    }
    cout << '\n';
  }
}