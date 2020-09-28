#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> split(string s, string delimiters) {
  // Create a C string from C++ string
  char str[s.size() + 1];
  strcpy(str, s.c_str()); 

  // Create a const C string from C++ delimiter
  const char *d = delimiters.c_str();

  // Initialize token
  char *token = strtok(str, d);
  vector<string> result;
  while (token != NULL) {
    string word(token);
    result.push_back(word);
    token = strtok(NULL, d); 
  }
  return result;
}

int main() {
  int t;
  int n;
  int size;
  map<string, int> dict;
  
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      // Name
      string name;
      cin >> name;
      name = name.substr(0, name.size() - 1);
      // Subclasses
      string class_;
      cin >> class_;
      vector<string> subclasses;
      subclasses = split(class_, "-");
      size = max((int)subclasses.size(), size);
      reverse(subclasses.begin(), subclasses.end());
      int x = 0;
      for (int k = 0, len = subclasses.size(); k < len; k++) {
        x = x * 10 + (subclasses[k] == "upper" ? 3 :
                      subclasses[k] == "middle" ? 2 : 1);
      }
      dict.insert(pair<string, int>(name, x));

      // Dummy
      string dummy;
      cin >> dummy;
    }
  }

  map<int, vector<string> > r;
  map<string, int>::iterator it;
  vector<int> vec;

  for( it = dict.begin(); it != dict.end(); it++) {
    string key = it->first;
    int v = it->second;
    for (int i = to_string(v).size(); i < size; i++) {
      v = v * 10 + 2;
    }
    if (r.find(v) != r.end()) {
      r[v].push_back(key);
    } else {
      vector<string> pq;
      pq.push_back(key);
      r.insert(pair<int, vector<string> >(v, pq));
      vec.push_back(v);
    }
  }

  sort(vec.begin(), vec.end());
  for (int i = vec.size() - 1; i >= 0; i--) {
    vector<string> pq = r[vec[i]];
    sort(pq.begin(), pq.end());
    for (int j = 0; j < pq.size(); j++) {
      cout << pq[j] << endl;
    }
  }
  cout << "==============================" << endl;
}
