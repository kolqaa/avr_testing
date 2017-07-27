
size_t my_strnlen(const char *s, size_t maxlen)
{
  size_t i;

  for (i = 0; i < maxlen && s[i]; i++)
    ;
  return (i);
}
