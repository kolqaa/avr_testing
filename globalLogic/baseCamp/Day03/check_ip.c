
int check_ip(uint32_t ip, uint32_t na, uint32_t nm)
{
  if ((na | nm) != nm)
    {
      printf("Incorrect na");
      if ((ip & nm) ^ na)
	  return (1);
    }
  if ((ip & nm) == na)
    return (1);
  return (0);
}
