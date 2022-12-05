#include <stdio.h>
#include <string.h>

char  *ft_strstr(char *str, char *to_find) {
  int i;
  int j;

  if (to_find[0] == '\0') {
    return (str);
  }
  i = 0;
  while (str[i]) {
    j = 0;
    if (str[i] == to_find[j]) {
      while (str[i + j] == to_find[j]) {
        j++;
        if (!to_find[j])
          return(&str[i]);
        }
      }
    i++;
  }
  return (0);
}


int main() {
  char string[50];
  char substring[50];

  printf("Insert the principal string\n");
  fgets(string, 50, stdin);

  printf("Insert the substring:\n");
  fgets(substring, 50, stdin);

  printf("%s\n", ft_strstr(string, substring));
}
