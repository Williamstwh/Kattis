#include <cstdio>
 #include <cstdint>
 #include <limits>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int N, t;
  int profits[1440];
  float p;

  while (true) {
    scanf("%d", &N);
    if (N == 0) {
      break;
    }
    fill(profits, profits + 1440, -8);
    while (N--) {
      scanf("%d %f", &t, &p);
      profits[t] = ((int) (p * 100 + 0.5)) - 8;
    }
    int globalStart = 0;
    int globalEnd = 0;
    int localStart = 0;
    int localEnd = 0;
    int globalMax = INT32_MIN / 2, currentMax = INT32_MIN / 2;
    int current, cumulative;
    for (int i = 0; i < 1440; i++) {
      current = profits[i];
      cumulative = profits[i] + currentMax;
      if (current > cumulative) {
        localStart = i;
        localEnd = i;
        currentMax = current;
      } else {
        localEnd = i;
        currentMax = cumulative;
      };

      if (currentMax > globalMax) {
        globalStart = localStart;
        globalEnd = localEnd;
        globalMax = currentMax;
      }
    }
    if (globalMax <= 0) {
      printf("no profit\n");
    } else {
      printf("%.2f %d %d\n", ((float) globalMax) / 100, globalStart, globalEnd);
    }
  }
}