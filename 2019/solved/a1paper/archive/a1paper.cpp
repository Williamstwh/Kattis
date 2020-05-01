#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

bool canFill(int paperSize, vector<int> &sizes, int smallestSize, float *totalLength, float width) {
  if (sizes[paperSize] > 0) {
    sizes[paperSize]--;
    return true;
  } else if (paperSize == smallestSize) {
    return false;
  } else {
    *totalLength += width;
    return canFill(paperSize + 1, sizes, smallestSize, totalLength, (1 / sqrt(2)) * width) &&
           canFill(paperSize + 1, sizes, smallestSize, totalLength, (1 / sqrt(2)) * width);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> sizes;
  sizes.push_back(0);
  sizes.push_back(0);
  for (int i = 0; i < n - 1; i++) {
    int s;
    cin >> s;
    sizes.push_back(s);
  }
  float totalLength = 0;
  if (canFill(1, sizes, n, &totalLength, pow(2.0, -3.0 / 4))) {
    cout << setprecision(12) << totalLength << endl;
  } else {
    cout << "impossible" << endl;
  }
}