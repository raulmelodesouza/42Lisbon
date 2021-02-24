#include "libft.h"

static char  *ft_strcpy(char *dest, char const *src)
{
  char *tmp;

  tmp = dest;
  while (*src != '\0')
  {
    *tmp = *src;
    tmp++;
    src++;
  }
  *tmp = '\0';
  return (dest);
}

static char  *ft_strcat(char *s1, const char *s2)
{
  size_t i;

  i = ft_strlen(s1);
  while ((s1[i] = *s2++))
    i++;
  return (s1);
}

char  *ft_strjoin(char const *s1, char const *s2)
{
  char  *dest;

  if (s1 && s2)
  {
    if (!(dest = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
      return (NULL);
    ft_strcpy(dest, s1);
    ft_strcat(dest, s2);
    return (dest);
  }
  else
    return (NULL);
}