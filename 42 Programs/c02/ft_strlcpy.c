#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int res;

	i = 0;
	res = 0;
	while (src[res])
		res++;
	if (size < 1)
		return (res);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (res);
}

int main() {
  char string[50];
  char shit[50];
  int size = 10;

  printf("Insert a string:\n");
  fgets(string, 50, stdin);
  string[strlen(string) - 1] = '\0';

  printf("Insert another string:\n");
  fgets(shit, 50, stdin);
  shit[strlen(shit) - 1] = '\0';

  printf("%d\n", ft_strlcpy(string, shit, size));
}
