#include <stdio.h>
#include <string.h>

int ft_str_is_numeric(char *str) {
  int i;
  int universal;

  universal = 1;
  i = 0;
  while (str[i] != '\0') {
    if (!(str[i] >= '0' && str[i] <= '9')) {
      universal = 0;
    }
      i++;
  }
  return (universal);
}

int main() {
  char string[50];

  printf("Insert a string:\n");
  fgets(string, 50, stdin);
  string[strlen(string) - 1] = '\0';

  printf("%d\n", ft_str_is_numeric(string));
}
