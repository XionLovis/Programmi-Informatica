#include <unistd.h>
#include <stdio.h>

void ft_print_numbers(void)
{
  char number;

  number = 48;
  while (number <= 57)
  {
    write(1, &number, 1);
    number++;
  }
}

int main(void)
{
  ft_print_numbers();
}
