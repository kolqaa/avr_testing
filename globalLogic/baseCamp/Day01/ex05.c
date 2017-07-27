/* Write a program that finds the
smallest of several integers. Assume that the first value
read specifies the number of values remaining.*/

#include <stdio.h>
#include <stdlib.h>

void	clear_input_buff(void)
{
  while (getchar() != '\n')
    ;
}

int main(void)
{
  int i = 0;
  int num = 0;
  int j = 0;
  int start_size = 10;
  int newsize = 5;
  int *tab;
  int smallest;

  tab = (int *)malloc(sizeof(int) * (start_size));
  printf("Enter several numbers when you enter all of your value press any button from 'A' to 'Z': ");

  while ((scanf("%d", &num)) == 1)
    {
      clear_input_buff();
      if (i > start_size) {
	  newsize = start_size + newsize;
	  tab = (int *)realloc(tab, sizeof(int) * (newsize));
	}
      tab[i] = num;
      i++;
    }
  i--;
  smallest = tab[i];
  while (j < i)
    {
      if (tab[j] < smallest)
	smallest = tab[j];
      j++;
    }
  printf("The smallest is %d\n", smallest);
  free(tab);
  return (0);
}
