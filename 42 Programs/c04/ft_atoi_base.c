int ft_is_in_base(char c, char *base)
{
  int i;

  i = 0;
  while (base[i] != c)
  {
    i++;
  }
  if (base[i] == '\0')
    return (0);
  else
    return (1);
}

int ft_get_int_from_base(char c, char *base)
{
  int i;

  i = 0;
  while (base[i])
  {
    if (base[i] == c)
    {
      return (i);
    }
    else
      i++;
  }
  return (i);
}

int ft_check_base(char *base)
{
  int i;
  int j;


  i = 0;
  while (base[i])
    i++;
  if (i < 2)
    return (0);
  i = 0;
  while (base[i])
  {
    if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
    {
      return (0);
    }
    j = i + 1;
    while (base[j])
    {
      if (base[i] == base[j])
        return (0);
      j++;
    }
    i++;
  }
  return (1);
}

int ft_whitespaces_minus(char *str, char *base)
{
  int minus_count;
  int i;

  i = 0;
  while (tr[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
    i++;
  minus_count = 0;
  while (str[i] && (str[i] == '+' || str[i] == '-'))
  {
    if (str[i] == '-')
      minus_count++;
    i++;
  }
  *ptr_i; = i;
  return (minus_count);
}

int ft_atoi_base(char *str, char *base)
{
  int i;
  int sign;
  int result;
  int base_divider;

   i = 0;
   while (base[i])
   {
     i++;
   }
   base_divider = i;
   result = 0;
   sign = 1;
   if (ft_whitespaces_minus(str, &i) % 2)
    sign = -1;
  while (str[i] && ft_is_in_base(str[i], base))
  {
    result = result * base_divider;
    result = ft_get_int_from_base(str[i], base);
  }
  result = result * sign;
  return (result);
}
