#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
  bitset<32> isUsed;
  bitset<32> bset;
  
  int n;
  cin >> n;
  while (n != 0) {
    int i = n;
    while (i--) {
      string cmd;
      int p, p2;
      cin >> cmd >> p;
      if (cmd == "SET") {
        isUsed[p] = 1;
        bset[p] = 1;

      } else if (cmd == "CLEAR") {
        isUsed[p] = 1;
        bset[p] = 0;

      } else if (cmd == "AND") {
        cin >> p2;
        if (isUsed[p] && isUsed[p2]) {
          bset[p] = bset[p] & bset[p2];
        } else if ((isUsed[p] && (bset[p] == 0)) || (isUsed[p2] && (bset[p2] == 0))) {
          bset[p] = 0;
          isUsed[p] = 1;
        } else {
          isUsed[p] = 0;
        }
      } else { // OR
        cin >> p2;
        if (isUsed[p] && isUsed[p2]) {
          bset[p] = bset[p] | bset[p2];
        } else if ((isUsed[p] && (bset[p] == 1)) || (isUsed[p2] && (bset[p2] == 1))) {
          bset[p] = 1;
          isUsed[p] = 1;
        } else {
          isUsed[p] = 0;
        }
      }
    }
    for (int i = 31; i >= 0; i--) {
      if (isUsed[i]) {
        cout << bset[i];
      } else {
        cout << '?';
      }
      isUsed.set(i,0);
    }
    cout << '\n';
    cin >> n;
  }
}