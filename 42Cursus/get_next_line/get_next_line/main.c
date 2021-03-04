/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmelo-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:29:20 by rmelo-de          #+#    #+#             */
/*   Updated: 2021/03/04 13:55:58 by rmelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char **line;
    int ret;

    fd = open("text.txt", O_RDONLY);
    if (!(line = (char **)malloc(sizeof(char*) * 10000)))
        return (0);

    while ((ret = get_next_line(fd, line)) > 0)
    {
        printf("%s\n", *line);
        printf("%i\n", ret);
        free(*line);
    }
    printf("%s\n", *line);
    printf("%i\n", ret);
    free(line);
    return(0);
}
