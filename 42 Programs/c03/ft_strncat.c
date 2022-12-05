#include <stdio.h>
#include <string.h>

char  *ft_strncat(char *dest, char *src, unsigned int nb) {
  unsigned int  i;
  unsigned int  j;

  i = 0;
  j = 0;
  while (dest[i] != '\0') {
    i++;
  }
  while ((src[j] != '\0') && j < nb) {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = '\0';
  return (dest);
}

int main() {
  char dest[20];
  char src[10];
  unsigned int nb = 5;

  printf("Insert the destination string:\n");
  fgets(dest, 20, stdin);
  dest[strlen(dest) - 1] = '\0';

  printf("Insert the source string:\n");
  fgets(src, 10, stdin);
  src[strlen(src) - 1] = '\0';

  printf("Modified string: %s\n", ft_strncat(dest, src, nb));
}
