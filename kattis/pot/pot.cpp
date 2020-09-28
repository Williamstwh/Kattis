#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  long sum = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int size = s.size();
    long e = stol(s.substr(size - 1, size));
    long base = stol(s.substr(0, size - 1));
    sum += pow(base, e);
  }
  cout << sum << endl;
}