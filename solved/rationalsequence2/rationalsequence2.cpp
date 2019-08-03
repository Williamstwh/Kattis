#include <stdio.h>

int getIndex(int p, int q) {
  if (p == q) {
    return 1;
  } else if (p > q) {
    return 2 * (getIndex(p - q, q)) + 1;
  } else {
    return 2 * getIndex(p, q - p);
  }
}

int main() {
  int TC, n, p, q;
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d %d/%d", &n, &p, &q);
    printf("%d %d\n", n, getIndex(p, q));
  }
}