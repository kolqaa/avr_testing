void clear_bits(int *val, int mask)
{
  mask = ~mask;
  *val = *val & mask;
}
