#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int sortedArr[n];
  int arr[n];
  int m;
  int min = INT32_MAX;
  for (int i = 0; i < n; i++) {
    cin >> m;
    sortedArr[i] = m;
    arr[i] = m;
  }
  sort(sortedArr, sortedArr + n);
  int count = 0;
  int max = INT16_MIN;
  for (int i = 0; i < n; i++) {
    count += (arr[i] == sortedArr[i] && arr[i] > max);
    max = arr[i] > max ? arr[i] : max;
  }
  cout << count << "\n";
}