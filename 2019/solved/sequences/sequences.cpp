#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int,int,int> iii;
typedef vector<iii> viii;

int main() {
  viii v;
  v.push_back(make_tuple(1, 0, 0));
  v.push_back(make_tuple(1, 0, 0));
  v.push_back(make_tuple(1, 0, 0));
  for (int i = 1; i < 3; i++) {
    iii a = v[i - 1];
    iii b = v[i];
    int a0 = get<0>(a), a1 = get<1>(a), a2 = get<2>(a),
      b0 = get<0>(b), b1 = get<1>(b), b2 = get<2>(b);
    v[i] = make_tuple(
      2 * (a0 + b0) + 1,
      2 * (a1 + b1) + 1,
      (a1 + 1) * (b0) + (a1) * (b0 + 1) + 2 * ( a2 + b2 ) 
    );
  }
  cout << get<2>(v[2]) << endl;
}