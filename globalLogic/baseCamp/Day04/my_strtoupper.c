
char *my_strtoupper(char *s, size_t len)
{
  size_t i;
  size_t k;
  char *out;

  if (!s)
    return (NULL);

  i = 0;
  while (s[i])
    i++;

  k = 0;
  out = (char*)malloc(sizeof(char) * (i + 1));
  
  for (i = 0; s[i] && i < len; i++, k++)
    out[k] = s[i];
  out[k] = '\0';

  for (i = 0; out[i]; i++)
    {
      if (out[i] >= 'a' && out[i] <= 'z')
	out[i] -= 32;
    }
   return (out);
}
