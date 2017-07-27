/*(Calculating the Value of π) Calculate the value of π from
  the infinite series */
#include <stdio.h>

int main(void)
{
  int i = 3;
  int count = 0;
  float pi = 4.0;

  while (i <= 1000)
    {
      if (count % 2 == 0) {
	pi -= 4.0 / (float)i;
	printf("%0.2f\t", pi);
      } 
      else {
	pi += 4.0 / (float)i;
	printf("%0.2f\t", pi);
      }
      count++;
      i += 2;
    }
  printf("\n");
  return (0);
}
	

