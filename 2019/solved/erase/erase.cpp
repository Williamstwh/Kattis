#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
  int n;
  string s1;
  string s2;
  cin >> n;
  cin >> s1;
  cin >> s2;
  int x = s1.size();
  bool valid = true;
  if (n % 2 == 0) {
    for (int i = 0; i < x; i++) {
      if (s1[i] != s2[i]) {
        valid = false;
        break;
      }
    }
  } else {
    for (int i = 0; i < x; i++) {
      if (s1[i] == s2[i]) {
        valid = false;
        break;
      }
    }
  }
  cout << (valid ? "Deletion succeeded\n" : "Deletion failed\n");
}