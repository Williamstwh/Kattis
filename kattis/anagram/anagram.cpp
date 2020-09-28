#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

unsigned long long factorialTable[201];
bool calculated[201];

unsigned long long factorial(unsigned long long n) {
  if (calculated[n]) {
    return factorialTable[n];
  } else {
    factorialTable[n] = n * factorial(n - 1);
    calculated[n] = true;
    return factorialTable[n]; 
  }
};

int main() {
  factorialTable[0] = 1;
  calculated[0] = true;
  cout.precision(100);
  cout << factorial((unsigned long long) 40) << endl;
}