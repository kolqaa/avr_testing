#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_error(int quotient)
{
  if (quotient)
    printf("Can't find out quotient, it cannot be divided by zero\n");
  else
    printf("Can't find out remainder, it cannot be divided by zero\n");
}

int	main(int argc, char **argv)
{
  if (argc != 3)
    {
      printf("Usage: [program take two numbers and show their sum, product, difference, quotient and remainder\n");
      return (0);
    }

  printf("The sum of %s and %s is %d\n", argv[1], argv[2], atoi(argv[1]) + atoi(argv[2]));
  printf("The product of %s and %s is %d\n", argv[1], argv[2], atoi(argv[1]) * atoi(argv[2]));
  printf("The difference of %s and %s is %d\n", argv[1], argv[2], atoi(argv[1]) - atoi(argv[2]));
  atoi(argv[2]) == 0 ? ft_error(1) : printf("The quotient of %s and %s is %d\n", argv[1], argv[2], atoi(argv[1]) / atoi(argv[2]));
  atoi(argv[2]) == 0 ? ft_error(0) : printf("The remainder of %s and %s is %d\n", argv[1], argv[2], atoi(argv[1]) % atoi(argv[2]));
  return (0);
}
