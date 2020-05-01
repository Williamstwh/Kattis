#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, X, Y, T;
  cin >> N;
  T = N;
  vector<bool> h(N, false);
  vector<bool> v(N, false);
  vector<bool> ld(2 * N - 1, false);
  vector<bool> rd(2 * N - 1, false);

  bool isValid = true;
  while (T--) {
    cin >> X >> Y;
    int ldv = X + Y;
    int rdv = (N - 1 - X) + Y;
    if (h[X] || v[Y] || ld[ldv] || rd[rdv]) {
      isValid = false;
      break;
    } else {
      h[X] = true;
      v[Y] = true;
      ld[ldv] = true;
      rd[rdv] = true;
    }
  }
  cout << (isValid ? "CORRECT\n" : "INCORRECT\n");
}