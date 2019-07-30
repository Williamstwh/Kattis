#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int TC, N;
  unordered_set<int> s;
  cin >> TC;
  while (TC--) {
    cin >> N;
    int pos[N + 1];
    s = *(new unordered_set<int>());

    for (int i = 1; i <= N; i++) {
      cin >> pos[i];
    }

    int min = N + 1;
    for (int i = N; i > 0; i--) {
      if (pos[i] < min) {
        s.insert(pos[i]);
        min = pos[i];
      }
    }
    cout << N - s.size() << '\n';
    for (int i = 1; i <= N; i++) {
      if (s.find(i) == s.end()) {
        cout << i << '\n';
      }
    }
  }
}