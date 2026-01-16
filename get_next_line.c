/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:28:32 by koodal            #+#    #+#             */
/*   Updated: 2026/01/16 15:16:49 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <stdio.h> //printf
#include <fcntl.h> //O_RDONLY stuff
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

char *until_nl(int fd, char *buffer)
{
    static char *stash;
    int rd_bytes;
    
    if (fd <= 0)
        return (NULL);
    if (stash == NULL)
        stash = strdup("");
    rd_bytes = 1;
    while (rd_bytes > 0)
    {
        rd_bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[rd_bytes] = '\0';
        printf("buffer read: %s\n", buffer);
        printf("rd_byte: %d\n", rd_bytes);
    }

    return (buffer);
}

int main (void)
{
    int fd;
    char *line_until_nl;
    char *buffer;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (-1);
    printf("[fd value]: %i\n", fd);
    // BUFFER_SIZE = 4 in default
    buffer = malloc(BUFFER_SIZE + 1);
    line_until_nl = until_nl(fd, buffer);
    printf("\n[return value of until_nl]\n%s\n", line_until_nl);
    free(buffer);
    buffer = NULL;
    close(fd);
    return (0);
}
