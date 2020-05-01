#include <iostream>
#include <string>
#include <cstring>
#include <deque>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  deque<int> firstHalf;
  deque<int> secondHalf;
  int fhSize = 0, shSize = 0;
  
  int n;
  string c;
  int x;
  
  cin >> n;
  
  while (n--) {
    cin >> c >> x;

    if (c == "push_back") {
      secondHalf.push_back(x);
      shSize++;
      if (fhSize < shSize) {
        firstHalf.push_back(secondHalf.front());
        fhSize++;
        secondHalf.pop_front();
        shSize--;
      }

    } else if (c == "push_front") {
      firstHalf.push_front(x);
      fhSize++;
      if (fhSize > shSize + 1) {
        secondHalf.push_front(firstHalf.back());
        shSize++;
        firstHalf.pop_back();
        fhSize--;
      }

    } else if (c == "push_middle") {
      if (fhSize > shSize) {
        secondHalf.push_front(x);
        shSize++;
      } else {
        firstHalf.push_back(x);
        fhSize++;
      }

    } else {
      if (x < fhSize) {
        cout << firstHalf[x] << "\n";
      } else {
        cout << secondHalf[x - fhSize] << "\n";
      }
    }
  }
}
