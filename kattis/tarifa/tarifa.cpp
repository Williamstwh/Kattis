#include <iostream>
using namespace std;

int main() {
  int x;
  int n;
  int c;
  int u = 0;
  cin >> x;
  cin >> n;
  int i = n;
  while (i--) {
    cin >> c;
    u += c;
  }
  cout << (n + 1) * x - u << '\n';
}