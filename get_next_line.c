/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:28:32 by koodal            #+#    #+#             */
/*   Updated: 2025/12/11 14:54:26 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

void newline_count(char *buffer)
{
    while (*buffer && *buffer != '\0')
    {
        if (*buffer == '\n')
            *buffer = '\\';
        printf("%c", *buffer);
        buffer++;
    }
}

static char *read_file(int fd)
{
    int file_read;
    char *line_buff;
    static int count = 1;
    
    printf("malloc#[%d]---", count++);
    line_buff = calloc(BUFFER_SIZE + 1, sizeof(char));
    if (line_buff == NULL)
        return (NULL);
    file_read = read(fd, line_buff, BUFFER_SIZE);
    //newline_count(line_buff);
    if (file_read <= 0)
    {
        free (line_buff);
        return (NULL);
    }
    return (line_buff);
}

char *get_next_line(int fd)
{
    char *next_line_buff;
    next_line_buff = read_file(fd);
    return (next_line_buff);
}

int main (void)
{
    int fd;
    char *res;
    int main_count;

    main_count = 0;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening File");
        return (1);
    }
    while (1)
    {
        res = get_next_line(fd);
        if (res == NULL)
            break;
        main_count++;
        printf("[%d]:%s\n", main_count, res);
        free(res);
        res = NULL;
    }
    close(fd);
    return (0);
}
