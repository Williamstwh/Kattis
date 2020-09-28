#include <stdio.h>

int main() {
  int sw, sr;
  while (scanf("%d %d", &sw, &sr) == 2) {
    if (sw == 0 && sr == 0) {
      break;
    } else if (sw + sr == 13) {
      printf("%s", "Never speak again.\n");
    } else if (sw > sr) {
      printf("%s", "To the convention.\n");
    } else if (sw < sr) {
      printf("%s", "Left beehind.\n");
    } else {
      printf("%s", "Undecided.\n");
    }
  }
}