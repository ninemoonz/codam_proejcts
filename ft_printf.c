/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:29 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/25 16:08:57 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

// for va_list, va_start, va_arg, va_end functions

int ft_printf_test1(const char *format, ...)
{
    va_list args;
    int count;
    char *str;
    unsigned int count;

    count = 0;
    while (str[count])
    {
        if (str[count] == '\0')
            return (1);
        write(1, &str[count], 1);
        count++;
    }
    return (0);
}


int main (void)
{
    char *str = "hello world!";
    ft_printf_test1(str);
    return (0);
}