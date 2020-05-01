#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  int lines;
  string s;
  getline(cin, s);
  istringstream iss(s);
  iss >> lines;

  for (int i = 0; i < lines; i++) {
    getline(cin, s);
    istringstream iss(s);
    int n;
    iss >> n;
    double values[n];
    double average = 0;
    for (int i = 0; i < n; i++) {
      double c;
      iss >> c;
      average += c;
      values[i] = c;
    }
    average /= n;

    int count = 0;
    for (int i = 0; i < n; i++) {
      count += (values[i] > average);
    }
    count *= 100;
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(3);
    cout << ((double) count / n) << "%" << endl;
  }
}
