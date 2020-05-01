#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <regex>
using namespace std;

int evaluate(istringstream *input, map<string, int> *stringToInt, int acc, char op) {
  if (op == '=') {
    return acc;
  } else {
    string variable;
    char nextOp;
    (*input) >> variable >> nextOp;
    map<string, int>::iterator it = (*stringToInt).find(variable);
    if (it == (*stringToInt).end()) {
      throw " unknown";
    }
    int value = it->second;

    switch (op) {
      case '+': return evaluate(input, stringToInt, acc + value, nextOp);
      case '-': return evaluate(input, stringToInt, acc - value, nextOp);
      default: return 0;
    }
  }
}

int main() {
  map<string, int> stringToInt;
  map<int, string> intToString;

  string line;
  while (getline(cin, line)) {
    istringstream iss(line);
    string command;
    iss >> command;
    if (command == "def") {
      string variable;
      int value;
      iss >> variable >> value;
      stringToInt[variable] = value;
      intToString[value] = variable;
    } else if (command == "calc") {
      string output = line.substr(5, line.length());
      output = regex_replace(output, regex("^ +| +$|( ) +"), "$1");
      try {
        int value = evaluate(&iss, &stringToInt, 0, '+');
        if (intToString[value] == "") {
          throw " unknown";
        }
        cout << output << ' ' << intToString[value] << endl;
      } catch (const char* msg) {
        cout << output << msg << endl;
      }
    } else if (command == "clear") {
      stringToInt = *(new map<string, int>());
      intToString = *(new map<int, string>());
    }
  }
}