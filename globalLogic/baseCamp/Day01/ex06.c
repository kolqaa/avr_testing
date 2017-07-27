/*Write a program that estimates the value of
the mathematical constant e by using the formula:
1 1 1 1
e = 1 + --- + --- + --- + … + --- + …
1! 2! 3! n! */

#include <stdio.h>

int main(void)
{
  int n = 0;
  int factorial = 1;
  float e = 1.0;

 beggin:
  printf("Enter accuracy of e: ");
  scanf("%d", &n);
  if (n < 0) {
    printf("Please enter positive value\n");
    goto beggin;
  }
  for (int i = 1; i <= n; i++) {
    for (int counter = 1; counter <= i; counter++) {
      factorial = factorial * counter;
    }
    e = e + ((float)1/factorial);
    factorial = 1;
  }
  printf("Result is: %.2f\n", (float)e);
  return (0);
}
