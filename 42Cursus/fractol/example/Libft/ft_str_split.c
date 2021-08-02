#include "libft.h"

static size_t	get_length(char *s, char *sample)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (ft_is_in(*s++, sample))
			continue ;
		count++;
		while (*s && !ft_is_in(*s, sample))
			s++;
	}
	return (count);
}

char	**ft_str_split(char *s, char *sample)
{
	char	**strs;
	char	**sav_strs;
	char	*sav_s;

	if (!s || !sample)
		return (0);
	strs = malloc((get_length(s, sample) + 1) * sizeof(char *));
	sav_strs = strs;
	while (*s)
	{
		if (ft_is_in(*s, sample))
		{
			s++;
			continue ;
		}
		sav_s = (char *)s;
		while (*s && !ft_is_in(*s, sample))
			s++;
		*strs = malloc((s - sav_s + 1) * sizeof(char));
		if (!*strs)
			return (0);
		ft_strlcpy(*strs++, sav_s, s - sav_s + 1);
	}
	*strs = 0;
	return (sav_strs);
}
