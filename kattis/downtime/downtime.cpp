#include <iostream>
#include <deque>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, rps;
  cin >> r >> rps;

  int t;
  deque<int> times;
  int size = 0;
  int max = 0;
  int localMax = 0;

  while (r--) {
    cin >> t;
    times.push_back(t);
    size++;
    while (times.front() + 1000 <= t) {
      times.pop_front();
      size--;
    }
    localMax = size % rps == 0 ? size / rps : size / rps + 1;
    max = max > localMax ? max : localMax;
  }
  cout << max << "\n";
}