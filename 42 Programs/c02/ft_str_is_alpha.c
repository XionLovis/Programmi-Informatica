#include <stdio.h>
#include <string.h>

int ft_str_is_alpha(char *str) {
  int universal;
  int i;

  i = 0;
  universal = 1;
  while (str[i] != '\0') {
    if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z'))
    {
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

  printf("%d\n", ft_str_is_alpha(string));
}
