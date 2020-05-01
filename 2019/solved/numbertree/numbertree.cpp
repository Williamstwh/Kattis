#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  int n;
  int r = 1;
  string s;
  cin >> n >> s;
  for (int i = 0, l = s.length(); i < l; i++) {
    r *= 2;
    if (s[i] == 'R') {
      r++;
    }
  }
  cout << ((int) pow(2, n + 1)) - r << '\n';
}