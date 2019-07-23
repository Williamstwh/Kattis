#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> inventory;
  vector<int> required;

  // A0 Size
  inventory.push_back(0);
  required.push_back(0);

  // A1 Size
  inventory.push_back(0);
  required.push_back(1);

  // Fill the rest of the sizes
  for (int i = 0; i < n - 1; i++) {
    int s;
    cin >> s;
    inventory.push_back(s);
    required.push_back(0);
  }

  double totalLength = 0;
  double currentWidthLength = pow(2, -3.0 / 4);
  for (int size = 1; size <= n; size++) {
    int diff = required[size] - inventory[size];
    if (diff <= 0) {
      cout << setprecision(12) << totalLength << endl;
      break;
    } else if (size == n) {
      cout << "impossible" << endl;
      break;
    } else {
      totalLength += currentWidthLength * (diff);
      currentWidthLength /= sqrt(2);
      required[size + 1] = 2 * (diff);
    }
  }
}