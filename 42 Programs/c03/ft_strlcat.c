unsigned int  ft_strlen(char *string) {
  unsigned int  i;

  i = 0;
  while (string[i] != '\0') {
    i++
  }
  return (i);
}

unsigned int  ft_strlcat(char *dest, char *src, unsigned int size) {
  unsigned int  i;
  unsigned int  dest_size;
  unsigned int  src_size;

  i = 0;
  dest_size = ft_strlen(dest);
  src_size = ft_strlen(src);
  if (size == 0)
    return (src_size + size);
  while (src[i] && dest_size < size - 1) {
    dest[dest_size] = src[i];
    dest_size++;
    i++;
  }
  dest[dest_size] = '\0';
  if (size < src_size)
    return (src_size + size);
  else
    return (dest_size + src_size);
}
