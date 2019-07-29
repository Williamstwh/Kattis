#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string m;
  int d;
  cin >> m >> d;
  if ((m == "OCT" && d == 31) || (m == "DEC" && d == 25)) {
    cout << "yup\n";
  } else {
    cout << "nope\n";
  }
  return 0;
}
