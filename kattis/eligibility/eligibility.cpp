#include <stdio.h>
#include <string>

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    char *name;
    int studyYear, studyMonth, studyDay;
    int birthYear, birthMonth, birthDay;
    int courses;
    scanf("%s %d/%d/%d %d/%d/%d %d", name, &studyYear, &studyMonth, &studyDay, &birthYear, &birthMonth, &birthDay, &courses);
    printf("%s %s",
           name, 
           studyYear >= 2010 || birthYear >= 1991 ? "eligible\n" :
           courses > 40 ? "ineligible\n": "coach petitions\n");
  }
}