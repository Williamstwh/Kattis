#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int statues;
  cin >> statues;
  cout << ((int) ceil(log2(statues))) + 1 << endl;
  return 0;
}