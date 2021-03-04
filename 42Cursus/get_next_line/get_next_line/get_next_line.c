/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:51:48 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/04 13:51:51 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	saveline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len); 

		tmp = ft_strdup(&((*s)[len + 1])); 

		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			free(*s);
			*s = NULL;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (1);
}

static int	output(char **s, char **line, int retorno, int fd)
{
	if (retorno < 0)
		return (-1); 
	else if (retorno == 0 && s[fd] == NULL)
		return (0);
	else
		return (saveline(&s[fd], line));
}


int			get_next_line(int fd, char **line)
{
	int			retorno;
	static char	*saved[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp; 

	if (fd < 0 || line == NULL)
		return (-1);
	while ((retorno = read(fd, buff, BUFFER_SIZE)) > 0) 
	{
		buff[retorno] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(saved[fd], buff);

			free(saved[fd]);
			saved[fd] = tmp;
		}
		if (ft_strchr(saved[fd], '\n')) 
			break ;
	}
	return (output(saved, line, retorno, fd));
}
