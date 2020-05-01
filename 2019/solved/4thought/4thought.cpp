#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

bool hasChar(string s, string c) {
  return s.find(c) != string::npos;
}

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

bool isOperator(string c) {
  string s = "+-*/";
  return c.size() == 1 && hasChar(s, c);
}

bool hasHigherPrecedence(string a, string b) {
  string lower = "+-";
  string higher = "*/";
  return !(hasChar(lower, a) && hasChar(higher, b));
}

queue<string> infixStringToPostfixQueue(string str) {
  // Convert Infix to Postfix
  vector<string> statement = split(str, " ");
  stack<string> s;
  queue<string> q;
  for (int i = 0, len = statement.size(); i < len; i++) {
    string c = statement[i];
    if (c == ")") {
      while (s.top() != "(") {
        q.push(s.top());
        s.pop();
      }
      s.pop();
    } else if (c == "(") {
      s.push(c);
    } else if (!isOperator(c)) {
      q.push(c);
    } else {
      while (!s.empty() && s.top() != "(" && hasHigherPrecedence(s.top(), c)) {
        q.push(s.top());
        s.pop();
      }
      s.push(c);
    }
  }
  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }
  return q;
}

int postfixQueueToAnswer(queue<string> q) {
  stack<int> s;
  while (!q.empty()) {
    string c = q.front();
    q.pop();
    if (isOperator(c)) {
      int op2 = s.top();
      s.pop();
      int op1 = s.top();
      s.pop();
      if (c == "+") {
        s.push(op1 + op2);
      } else if (c == "-") {
        s.push(op1 - op2);
      } else if (c == "*") {
        s.push(op1 * op2);
      } else if (c == "/") {
        s.push(op1 / op2);
      }
    } else {
      s.push(stoi(c));
    }
  }
  return s.top();
}

int evaluateExpr(string s) {
  return postfixQueueToAnswer(infixStringToPostfixQueue(s));
}

int main() {
  char ops[] = { '+', '-', '*', '/' };
  string expr = "4 %c 4 %c 4 %c 4";
  char buffer[expr.size() + 1];
  map<int, string> dict;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int n = sprintf(buffer, expr.c_str(), ops[i], ops[j], ops[k]);
        string s = buffer;
        int res = evaluateExpr(s);
        dict.insert(pair<int, string>(res, s + " = " + to_string(res)));
      }
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (dict[k] != "") {
      cout << dict[k] << endl;
    } else {
      cout << "no solution" << endl;
    }
  }
}
