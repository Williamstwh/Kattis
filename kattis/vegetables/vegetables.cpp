#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
  double r;
  int n;
  double c;
  double sm = INT32_MAX;
  priority_queue<double> pq;
  cin >> r >> n;
  while (n--) {
    cin >> c;
    sm = min(sm, c);
    pq.push(c);
  }

  int cuts = 0;
  while (sm < pq.top() * r) {
    double top = pq.top();
    pq.pop();
    int p = 2;
    while (top / p > pq.top()) {
      p++;
    }
    int pc = p;
    while (pc--) {
      pq.push(top / p);
    }
    cuts += p;
    sm = min(sm, top / p);
    if (cuts < 10) cout << top << '\n';
  }
}