#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  int arr1[26] = {};
  int arr2[26] = {};
  int r = 0;
  int s = 0;

  for (int i = 0; i < n; i++) {
    int c1 = s1[i] - 65;
    int c2 = s2[i] - 65;
    if (c1 == c2) {
      r++;
    } else {
      arr1[c1]++;
      arr2[c2]++;
    }
  }

  for (int i = 0; i < 26; i++) {
    s += min(arr1[i], arr2[i]);
  }
  cout << r << ' ' << s << '\n';
}