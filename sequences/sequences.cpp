#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int numberOfChars(string binary, char c) {
  int count = 0;
  for (int i = 0; i < binary.length(); i++) {
    if (binary[0] == c) {
      count++;
    }
  }
  return count;
}

int numberOfChars(string binary, int *inverses)[2] {
  int len = binary.length();
  if (binary == "1") {
    return { 0, 1 };
  } else if (binary == "0") {
    return { 1, 0 };
  } else {
    int mid = len / 2;
    string firstHalf = binary.substr(0, mid);
    string secondHalf = binary.substr(mid, len);
    int first[2] = numberOfChars(firstHalf, inverses);
    int second[2] = numberOfChars(secondHalf, inverses);
    *inverses += first[1] + second[0];
    return { first[0] + second[0], first[1] + second[1] };
  }
}

int main() {
  int n;
  cin >> n;
  int x;
  numberOfChars('100', &x);
  cout << x;
}
