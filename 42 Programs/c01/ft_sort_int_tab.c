#include <stdio.h>

void ft_sort_int_tab(int *array, int length) {
  int temp;
  int i;

  i = 0;
  while (i < (length - 1)) {
    if (array[i] > array[i + 1]) {
      temp = array[i];
      array[i] = array[length - 1];
      array[length - 1] = array[i];
    }
    else
      i++;
  }
}
