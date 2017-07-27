

size_t my_strlcpy(char *d, const char *s, size_t dsize)
{
  size_t len;

  if (!s)
    return (0);
  
  len = 0;
  while (s[len])
    len++;
  
  while (dsize > 1 && *s)
    {
      *d++ = *s++;
      dsize--;
    }
  
   if (dsize >= 1)
    *d = '\0';
  return (len);
}
