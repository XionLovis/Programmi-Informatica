int ft_strcmp(char *s1, char *s2)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (s1[i] != '\0')
  {
    i++;
  }
  while (s2[j] != '\0') {
    j++;
  }
  if (i != j)
    return (i - j);
  else
  {
    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      else
        i++;
    }
  }
  return (0);
}
