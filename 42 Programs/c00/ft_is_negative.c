#include <unistd.h>
#include <stdio.h>

void ft_is_negative(int n)
{
  if (n < 0)
  {
    write(1, "N", 1);
  }
  else
  {
    write(1, "P", 1);
  }
}

int main(void)
{
  int n;

  scanf("%d", &n);
  ft_is_negative(n);
}
