#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, P;
  cin >> N >> P;
  
  int arr[N];

  int x, max_global = -1, max_current = -1;
  while (N--) {
    cin >> x;
    x -= P;
    max_current = max(x, max_current + x);
    if (max_current > max_global) {
      max_global = max_current;
    }
  }
  cout << max_global << '\n';
}