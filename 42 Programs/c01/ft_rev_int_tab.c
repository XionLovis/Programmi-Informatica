#include <stdio.h>

void ft_rev_int_tab(int *array, int length) {
  int temp;
  int i;
  int j;

  i = 0;
  j = length - 1;
  while (i < (length / 2)) {
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    i++;
    j--;
  }
}
