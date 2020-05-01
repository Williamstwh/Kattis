#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
using namespace std;

int main() {
  string line;
  int time;
  char question;
  string correctness;
  bool isRight;

  map<char, int> wrongAttemptsCount;
  set<char> correctQuestions;
  int score = 0;

  while (true) {
    getline(cin, line);
    stringstream ss(line);
    ss >> time >> question >> correctness;
    if (time == -1) {
      break;
    }
    if(correctness == "right") {
      score += (time + wrongAttemptsCount[question] * 20);
      correctQuestions.insert(question);
    } else {
      wrongAttemptsCount[question]++;
    };
  }
  cout << correctQuestions.size() << ' ' << score << endl;
}
