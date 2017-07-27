
size_t my_strlen(char *s)
{
  size_t i;
  
  for(i = 0; s[i] ;i++)
    ;
  return (i);
}

