#include <stdio.h>
#include <string.h>

char  *ft_str_strupcase(char *str) {
  int i;

  i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
    }
    i++;
  }
  return (str);
}

int main() {
  char string[50];

  printf("Insert a string and the function will turn every letter in uppercase:\n");
  fgets(string, 50, stdin);
  string[strlen(string) - 1] = '\0';

  printf("Modified string: %s\n", ft_str_strupcase(string));
}
