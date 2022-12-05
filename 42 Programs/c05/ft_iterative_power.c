#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
  int i;
  int j;

  i = 1;
  j = nb;
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  while (i < power)
  {
    j = j * nb;
    i++;
  }
  return (j);
}

int main() {
  int nb;
  int power;

  printf("Insert a number: ");
  scanf("%d", &nb);
  printf("Insert the power of the number: ");
  scanf("%d", &power);
  printf("Here's the number: %d\n", ft_iterative_power(nb, power));
}
