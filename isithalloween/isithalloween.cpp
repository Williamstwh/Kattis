#include <stdio.h>
#include <string.h>

int main() {
  char *m;
  int d;
  scanf("%s %d", m, &d);
  if ((strcmp(m, "OCT") == 0 && d == 31) || (strcmp(m, "DEC") == 0 && d == 25)) {
    printf("%s", "yup\n");
  } else {
    printf("%s", "nope\n");
  }
  return 0;
}
