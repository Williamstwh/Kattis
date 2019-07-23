#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

unsigned long long numberOfOnes(unsigned long long binary) {
  return binary == 0 ? 0 : binary % 10 + numberOfOnes(binary / 10);
}

unsigned long long numberOfInverses(unsigned long long binary) {
  return binary == 0 ? 0 :
         binary % 10 == 1 ?
         numberOfInverses(binary / 10) :
         numberOfInverses(binary/ 10) + numberOfOnes(binary / 10);
}

unsigned long long numberOfSwapsNeeded(unsigned long long n) {
  return n == 1 ? 0 : 2 * numberOfSwapsNeeded(n - 1) + (n - 1) * pow(2, n - 2);
}

unsigned long long getAnswer(string str, map<string,int> &memoizedAnswers) {
  if (memoizedAnswers[str] != 0) {
    return memoizedAnswers[str];
  }
  unsigned long long index = str.find_first_of('?');
  if (index != string::npos) {
    string z_str = str;
    string o_str = str;
    z_str[index] = '0';
    o_str[index] = '1';
    return getAnswer(z_str, memoizedAnswers) + getAnswer(o_str, memoizedAnswers);
  } else {
    unsigned long long answer = numberOfInverses(atol(str.c_str()));
    memoizedAnswers.insert(pair<string,int>(str, answer));
    return answer;
  }
}

int main() {
  string str;
  map<string,int> memoizedAnswers;
  cin >> str;
  cout << getAnswer(str, memoizedAnswers) % ((unsigned long long) 1000000007) << endl;
  return 0;
}
