#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int s = 2;
  for (int i = 0; i < n; i++) {
    s = 2 * s - 1;
  }
  std::cout << s * s << '\n';
}