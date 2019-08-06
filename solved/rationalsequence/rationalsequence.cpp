#include <cstdio>

int main() {
  int P, i, p, q;
  scanf("%d", &P);
  while (P--) {
    // printf("Hello world\n");
    scanf("%d %d/%d\n", &i, &p, &q);
    if (q == 1) {
      printf("%d %d/%d\n", i, 1, p + 1);
    } else if (p < q) {
      printf("%d %d/%d\n", i, q, q - p);
    } else {
      int n = q;
      int times = p / q;
      p %= q;
      q -= p;
      p += q;
      q += times * p;
      printf("%d %d/%d\n", i, n, q);
    }
  }
}