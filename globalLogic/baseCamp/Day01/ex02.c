/*Write a program that inputs three different integers from the keyboard, then
prints the sum, the average, the product, the smallest and the largest of
these numbers.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
  int x;
  int y;
  int z;
  int flag;
  int tab[3];
}	       t_data;

void	sort_int_tab(int *tab, int size)
{
  int i;
  int j;
  int temp;
  
  i = 0;
  while (i < size)
    {
      j = i + 1;
      while (j < size) 
	{
	  if (tab[i] > tab[j]) {
	      temp = tab[i];
	      tab[i] = tab[j];
	      tab[j] = temp;
	    }
	  j++;
	}
      i++;
    }
}

void	clear_input_buff(void)
{
  while (getchar() != '\n');
}

int is_equal(int x, int y, int z)
{
  if (x == y && x == z && y == z)
    return (1);
  return (0);
}

void	take_numbers(t_data *data)
{
  printf("Enter three different integers: ");
  while (!data->flag)
    {
      if (!scanf("%d%d%d", &data->x, &data->y, &data->z)) {
        printf("Enter three numbers that consist only digits or \"Ctrl+Z\" for quit\n");
        clear_input_buff();
      }
      else {
        if (is_equal(data->x, data->y, data->z)) {
          printf("Three numbers should be different:");
          continue ;
        }
	data->tab[0] = data->x, data->tab[1] = data->y, data->tab[2] = data->z;
        data->flag = 1;
      }
    }
}

void	show_result(t_data *data)
{
  printf("Sum of %8d %5d %5d = %d\n", data->x, data->y, data->z, data->x + data->y + data->z);
  printf("Average of %4d %5d %5d = %d\n", data->x, data->y, data->z, (data->x + data->y + data->z) / 3);
  printf("Product of %4d %5d %5d = %d\n\n", data->x, data->y, data->z, data->x * data->y * data->z);
  printf("Smallest = %d\nLargest = %d\n", data->tab[0], data->tab[2]);
}
int main(void)
{
  t_data * data;

  data = (t_data *)malloc(sizeof(*data));
  memset(data, 0, sizeof(*data));

  take_numbers(data);
  sort_int_tab(data->tab, 3);
  show_result(data);

  free(data);
  return (0);
}
