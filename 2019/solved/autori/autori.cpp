#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
  string s;
  stringstream ss;
  cin >> s;
  replace(s.begin(), s.end(), '-', ' ');
  ss << s;
  string os;
  while (ss >> os) {
    cout << os[0];
  }
  cout << '\n';
}