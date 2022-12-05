#include <stdio.h>
#include <string.h>

char  *ft_strcapitalize(char *str) {
  int i;
  int next;

  i = 0;
  next = 1;
  while (str[i] != '\0') {
    if ((next == 1) && (str[i] >= 'a' && str[i] <= 'z')) {
      str[i] = str[i] - 32;
    }
    else if ((next == 0) && (str[i] >= 'A' && str[i] <= 'Z')) {
        str[i] = str[i] + 32;
      }
    if (str[i] < '0' || (str[i] > '9' && str[i] < 'A')
        || (str[i] < 'Z' && str[i] > 'a') || (str[i] > 122)) {
      next = 1;
    }
    else
      next = 0;
    i++;
  }
  return (str);
}


int main() {
  char string[50];

  printf("Insert a string: \n");
  fgets(string, 50, stdin);
  string[strlen(string) - 1] = '\0';

  printf("Modified string: %s\n", ft_strcapitalize(string));
}
