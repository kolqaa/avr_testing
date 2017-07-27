#include <stdio.h>
#include <string.h>

char *my_strrchr(const char *s, int c)
{
  int i;
  char *str;

  if (!s)
    return (NULL);
  str = (char *)s;
  i = 0;
  while (str[i])
    i++;
  while (i >= 0)
    {
      if (str[i] == c)
	return (&str[i]);
      i--;
    }
  if (str[i] == c)
    return (&str[i]);
  return (NULL);
}

int main(void)
{
  char *string = "";
  char *new1;
  char *new2;

  new1 = my_strrchr(string, 'w');
  new2 = strrchr(string , 'w');
  printf("my %s\n", new1);
  printf("sys %s\n", new2);
}
