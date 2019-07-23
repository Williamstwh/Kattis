#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  int remaining = 0;
  int fromLastMonth = 0;
  int n;
  while (cin >> n) {
    remaining = remaining + x - usedThisMonth;
  }
  cout << remaining;
}