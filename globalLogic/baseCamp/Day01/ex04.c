/*Palindrome Tester*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*strrev(char *str)
{
  int	i;
  int	len;
  char	temp;

  len = strlen(str) - 1;
  i = 0;
  while (len > i)
    {
      temp = str[len];
      str[len] = str[i];
      str[i] = temp;
      len--;
      i++;
    }
  return (str);
}

int	lentgh_value(int num)
{
  int	count = 0;

  while (num > 0)
    {
      num = num / 10;
      count++;
    }
  return (count);
}

char	*itoa(int num)
{
  int	i = 0;
  char	*str;

  if ((str = (char *)malloc(sizeof(char) * (lentgh_value(num) + 1))) == NULL)
    return (NULL);
  while (num > 9)
    {
      str[i] = (num % 10) + '0';
      num = num / 10;
      i++;
    }
  str[i++] = num + '0';
  str[i] = '\0';
  return (strrev(str));
}


void clear_input_buff(void)
{
  while (getchar() != '\n')
    ;
}

char *revers(char *str)
{
  int i = 0;
  char *newstr;
  char tmp;
  int len = strlen(str) - 1;

  newstr = (char *)malloc(sizeof(char) * (strlen(str) + 1));
  while (len >= 0)
      newstr[i++] = str[len--];
  newstr[i] = '\0';
  return (newstr);
}


int main(void)
{
  int num;
  int flag = 0;
  char *number1;
  char *number2;

  printf("Enter five-digit integer to know palindrome it is or not:");
  while (!flag)
    {
      if (!scanf("%d", &num)) {
	  printf("Enter only digit:");
	  clear_input_buff();
      }
      else {
	if (num < 0) {
	  printf("Enter only positive number:");
	  continue ;
	}
	if (lentgh_value(num) != 5) {
	  printf("%d is not five-digit number, enter only five-digit number:", num);
	    continue ;
	}
	flag = 1;
      }
    }
  number1 = itoa(num);
  number2 = revers(number1);
  if (!strcmp(number1, number2))
    printf("%s is a palindrome\n", number1);
  else
    printf("%s is not palindorme\n", number1);
  free(number1);
  free(number2);
  return (0);
}

