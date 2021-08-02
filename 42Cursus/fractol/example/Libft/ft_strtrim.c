/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:09:07 by jfigueir          #+#    #+#             */
/*   Updated: 2021/05/24 18:23:10 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp(const char c, const char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

static int	start_trim(char const *s1, char const *set)
{
	t_uint	i;

	i = 0;
	while (s1[i] && cmp(s1[i], set))
		i++;
	return (i);
}

static int	end_trim(char const *s1, char const *set, size_t length)
{
	t_uint	i;

	if (length == 0)
		return (0);
	i = 0;
	while ((length - 1 - i) && cmp(s1[length - 1 - i], set))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	t_uint	start;
	t_uint	end;
	size_t	length;

	if (!s1 || !set)
		return (0);
	length = ft_strlen(s1);
	start = start_trim(s1, set);
	end = end_trim(s1, set, length);
	if (start + end >= length)
	{
		ret = malloc(1);
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	else
		ret = malloc((length - start - end + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + start, length - start - end + 1);
	ret[length - start - end] = '\0';
	return (ret);
}
