#include <stdio.h>

int ft_iterative_factorial(int nb) {
  int i;

  i = nb;
  if (nb < 1)
    return (0);
  while (i > 1) {
    nb = nb * (i - 1);
    i--;
  }
  return (nb);
}

int main() {
  int a;

  printf("Insert a number: ");
  scanf("%d", &a);
  printf("Factorial of the number: %d\n", ft_iterative_factorial(a));
}
