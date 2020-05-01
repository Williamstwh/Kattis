#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  int x, y, z;
  string order;

  cin >> x >> y >> z;
  cin >> order;

  v.push_back(x);
  v.push_back(y);
  v.push_back(z);
  sort(v.begin(), v.end());

  string abc = "ABC";
  for (int i = 0; i < 3; i++) {
    cout << v[abc.find(order.at(i))];
    if (i == 2) {
      continue;
    }
    cout << " ";
  }
  cout << endl;
}

