#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  map<char, string> dict;
  dict.insert(pair<char, string>('a', "@"));
  dict.insert(pair<char, string>('b', "8"));
  dict.insert(pair<char, string>('c', "("));
  dict.insert(pair<char, string>('d', "|)"));
  dict.insert(pair<char, string>('e', "3"));
  dict.insert(pair<char, string>('f', "#"));
  dict.insert(pair<char, string>('g', "6"));
  dict.insert(pair<char, string>('h', "[-]"));
  dict.insert(pair<char, string>('i', "|"));
  dict.insert(pair<char, string>('j', "_|"));
  dict.insert(pair<char, string>('k', "|<"));
  dict.insert(pair<char, string>('l', "1"));
  dict.insert(pair<char, string>('m', "[]\\/[]"));
  dict.insert(pair<char, string>('n', "[]\\[]"));
  dict.insert(pair<char, string>('o', "0"));
  dict.insert(pair<char, string>('p', "|D"));
  dict.insert(pair<char, string>('q', "(,)"));
  dict.insert(pair<char, string>('r', "|Z"));
  dict.insert(pair<char, string>('s', "$"));
  dict.insert(pair<char, string>('t', "\'][\'"));
  dict.insert(pair<char, string>('u', "|_|"));
  dict.insert(pair<char, string>('v', "\\/"));
  dict.insert(pair<char, string>('w', "\\/\\/"));
  dict.insert(pair<char, string>('x', "}{"));
  dict.insert(pair<char, string>('y', "`/"));
  dict.insert(pair<char, string>('z', "2"));
  dict.insert(pair<char, string>('A', "@"));
  dict.insert(pair<char, string>('B', "8"));
  dict.insert(pair<char, string>('C', "("));
  dict.insert(pair<char, string>('D', "|)"));
  dict.insert(pair<char, string>('E', "3"));
  dict.insert(pair<char, string>('F', "#"));
  dict.insert(pair<char, string>('G', "6"));
  dict.insert(pair<char, string>('H', "[-]"));
  dict.insert(pair<char, string>('I', "|"));
  dict.insert(pair<char, string>('J', "_|"));
  dict.insert(pair<char, string>('K', "|<"));
  dict.insert(pair<char, string>('L', "1"));
  dict.insert(pair<char, string>('M', "[]\\/[]"));
  dict.insert(pair<char, string>('N', "[]\\[]"));
  dict.insert(pair<char, string>('O', "0"));
  dict.insert(pair<char, string>('P', "|D"));
  dict.insert(pair<char, string>('Q', "(,)"));
  dict.insert(pair<char, string>('R', "|Z"));
  dict.insert(pair<char, string>('S', "$"));
  dict.insert(pair<char, string>('T', "\'][\'"));
  dict.insert(pair<char, string>('U', "|_|"));
  dict.insert(pair<char, string>('V', "\\/"));
  dict.insert(pair<char, string>('W', "\\/\\/"));
  dict.insert(pair<char, string>('X', "}{"));
  dict.insert(pair<char, string>('Y', "`/"));
  dict.insert(pair<char, string>('Z', "2"));
  string s;
  getline(cin, s);
  unsigned int len = s.length();
  for (int i = 0; i < len; i++) {
    if (dict[s[i]].length() > 0) {
      cout << dict[s[i]];
    } else {
      cout << s[i];
    }
  }
  cout << endl;
}