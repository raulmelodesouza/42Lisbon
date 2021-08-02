/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:23:01 by jfigueir          #+#    #+#             */
/*   Updated: 2021/05/24 18:29:46 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s++ == c)
			continue ;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	**sav_strs;
	char	*sav_s;

	if (!s)
		return (0);
	strs = malloc((get_length(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	sav_strs = strs;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		sav_s = (char *)s;
		while (*s && *s != c)
			s++;
		*strs = malloc((s - sav_s + 1) * sizeof(char));
		ft_strlcpy(*strs++, sav_s, s - sav_s + 1);
	}
	*strs = 0;
	return (sav_strs);
}
