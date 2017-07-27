/*Write a program that reads in two integers and determines and prints if the
  first is a multiple of the second*/
#include <stdio.h>

void	clear_input_buff(void)
{    
  while ( getchar() != '\n' )
    ;
}

int main(void)
{
  int num1 = 0;
  int num2 = 0;
  int flag = 0;

  printf("Enter two numbers: \n");
  while (!flag)
    {
      if (!scanf("%d%d", &num1, &num2))	{
	  printf("Enter only two numbers that consist only digits or \"ctrl+z\" for exit\n");
	  clear_input_buff();
	} 
        else {
	  flag = 1;
	  break ;
	}
    }
  if ((num1 % num2) == 0)
    printf("%d is a multiple of %d\n", num1 , num2);
  else 
    printf("%d is not multiple of %d\n", num1, num2);
  return (0);
}
