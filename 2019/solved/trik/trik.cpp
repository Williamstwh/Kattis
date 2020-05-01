#include <iostream>
#include <string>
using namespace std;

int main() {
  bool c[3] = { 1, 0, 0 };
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      c[0] ^= c[1];
      c[1] ^= c[0];
      c[0] ^= c[1];
    } else if (s[i] == 'B') {
      c[1] ^= c[2];
      c[2] ^= c[1];
      c[1] ^= c[2];
    } else {
      c[0] ^= c[2];
      c[2] ^= c[0];
      c[0] ^= c[2];
    }
  }
  for (int i = 0; i < 3; i++) {
    if (c[i]) {
      cout << i + 1 << '\n';
      break;
    }
  }
}