#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int i;
  int l = INT32_MIN;
  vector<int> v;

  while (n--) {
    cin >> i;
    if (i > l) {
      v.push_back(i);
      l = i;
    }
  }
  int len = v.size();
  cout << len << "\n";
  cout << v[0];
  for(int i = 1; i < len; i++) {
    cout << ' ' << v[i];
  }
  cout << "\n";
}