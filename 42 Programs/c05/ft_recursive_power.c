#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
  int i;

  i = nb;
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (power > 0)
  {
    nb = nb * ft_recursive_power(nb, power - 1);
  }
  return (nb);
}

int main() {
  int nb;
  int power;

  printf("Insert a number: ");
  scanf("%d", &nb);
  printf("Insert the power of the number: ");
  scanf("%d", &power);
  printf("Here's the number with the recursive function: %d\n", ft_recursive_power(nb, power));
}
