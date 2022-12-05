#include <stdio.h>

int ft_recursive_factorial(int nb) {
  int i;

  i = nb;
  if (nb < 1)
    return (0);
  else {
    if (i == 1)
      return nb;
    else
      nb = nb * ft_recursive_factorial(nb - 1);
  }
  return nb;
}

int main() {
  int a;
  printf("Insert a number: ");
  scanf("%d", &a);
  printf("Factorial recursive of the number: %d\n", ft_recursive_factorial(a));
}
