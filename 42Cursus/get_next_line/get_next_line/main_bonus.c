/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:54:55 by kyuki             #+#    #+#             */
/*   Updated: 2021/03/05 13:27:14 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;

	(void)ac;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[1], O_RDONLY);
	fd3 = open(av[1], O_RDONLY);
	//fd2 = open(av[1], O_RDONL);
	get_next_line(fd1, &line);
	printf("fd1: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("fd3: %s\n", line);
	free(line);

	get_next_line(fd1, &line);
	printf("fd1: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("fd3: %s\n", line);
	free(line);

	get_next_line(fd1, &line);
	printf("fd1: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd3, &line);
	printf("fd3: %s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("fd1: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);

	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	get_next_line(fd2, &line);
	printf("fd2: %s\n", line);
	free(line);
	return (0);
}
