#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int isSubstr(string pw, string s) {
  if (pw == "") {
    return true;
  } else if (s == "" || pw[0] != s[0]) {
    return false;
  } else {
    return isSubstr(pw.substr(0, pw.size()), s.substr(0, s.size()));
  }
}

int main() {
  string pw;
  string s;
  string str = "";
  unordered_set<char> set;
  cin >> pw >> s;

  for (int i = 0, len = pw.size(); i < len; i++) {
    set.insert(pw[i]);
  }

  for (int i = 0, len = s.size(); i < len; i++) {
    if (set.find(s[i]) != set.end()) {
      str += s[i];
    }
  }

  bool isValid = false;
  for (int i = 0, len = s.size(); i < len; i++) {
    if (s[i] == pw[0]) {
      if (isSubstr(pw, s.substr(i, s.size()))) {
        isValid = true;
      }
    }
  }
  cout << str << '\n';
}