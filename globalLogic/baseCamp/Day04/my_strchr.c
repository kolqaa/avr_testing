
char *my_strchr(const char *s, int c)
{
  char *str;
  int i;
  
  if (!s)
    return (NULL);
  
  str = (char *)s;
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (&str[i]);
      i++;
    }
  return ((str[i] == c) ? &str[i] : NULL);
}

