#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main() {
  int numberOfCases, numberOfPeople;
  cin >> numberOfCases;
  for (int c = 0; c < numberOfCases; c++) {
    cin >> numberOfPeople;
    string dummy;
    getline(cin, dummy);

    int max = 0;
    map<string, int> personToScore;
    string persons[numberOfPeople];
    string scorePersons[numberOfPeople];

    for (int p = 0; p < numberOfPeople; p++) {
      string line;
      getline(cin, line);
      replace(line.begin(), line.end(), '-', ' ');
      stringstream ss(line);

      int base = 1;
      int score = 0;
      string word;
      ss >> word;
      string person = word.substr(0, word.length() - 1);
      persons[p] = person;
      while (word != "class") {
        ss >> word;
        score += (base * (word == "upper" ? 3 : word == "middle" ? 2 : word == "lower" ? 1 : 0));
        base *= 10;
      }
      int localMax = to_string(score).length();
      max = max > localMax ? max : localMax;
      personToScore[person] = score;
    }

    for (int i = 0; i < numberOfPeople; i++) {
      string person = persons[i];
      while (to_string(personToScore[person]).length() < max) {
        personToScore[person] = personToScore[person] * 10 + 2;
      }
      scorePersons[i] = to_string((int) (pow(10, max) - personToScore[person])) + person;
    }

    sort(scorePersons, scorePersons + numberOfPeople);

    for (int i = 0; i < numberOfPeople; i++) {
      
      cout << scorePersons[i].substr(max, scorePersons[i].length()) << endl;
    }
    cout << "==============================" << endl;
  }
}