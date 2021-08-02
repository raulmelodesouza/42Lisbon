/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:13:32 by jfigueir          #+#    #+#             */
/*   Updated: 2021/03/10 19:13:32 by jfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	src_size;
	size_t	dst_size;
	t_uint	i;
	t_uint	j;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	j = dst_size;
	i = 0;
	if (dst_size < n - 1 && n > 0)
	{
		while (src[i] && dst_size + i < n - 1)
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	if (dst_size >= n)
		dst_size = n;
	return (src_size + dst_size);
}
