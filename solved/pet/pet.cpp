#include <cstdio>

int main() {
  int a, b, c, d, s, i = 1, p = 0, m = 0;
  while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
    s = a + b + c + d;
    if (s > m) {
      p = i;
      m = s;
    }
    i++;
  }
  printf("%d %d\n", p, m);
}