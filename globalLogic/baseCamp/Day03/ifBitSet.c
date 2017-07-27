int ifset_bit(int val, int bit)
{
  size_t  mask = 1;
  return (val & (mask << (bit - 1)) ? 1 : 0);
}
