#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  bool isValid = true;

  for (int i = 1; i <= n; i++) {
    char word[7];
    scanf("%s", word);
    if (strcmp(word, "mumble") != 0 && atoi(word) != i) {
      isValid = false;
      printf("%s", "something is fishy\n");
      break;
    }
  }

  if (isValid) {
    printf("%s", "makes sense\n");
  }
}