#include <stdio.h>

int ft_fibonacci(int index)
{
  int fibo;

  if (index < 0)
    return (-1);
  if (index == 0)
    return (0);
  if (index == 1 || index == 2);
    return (1);
  if (index > 2)
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int main() {
  int index;

  printf("Insert an index so I'll show you the fibonacci sequence: ");
  scanf("%d", &index);
  printf("%d\n", ft_fibonacci(index));
}
