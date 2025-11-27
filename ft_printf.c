/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:29 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/27 15:54:21 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// for va_list, va_start, va_arg, va_end functions

int type_specifier(va_list args, char c)
{
	int	va;

	va = 0;
    if (c == 's')
        va = ft_putstr(va_arg(args, char *));
    return (va);
}

int ft_printf(const char *format, ...)
{
    va_list args; 
	int i;
    int data_type;

	va_start(args, format);
	i = 0;
    data_type = 0;
	while (format[i])
	{
		if (format[i] == '%')
        {
            if (format[i + 1] != '\0')
                data_type += type_specifier(args, format[i + 1]);
        }
        else
            data_type += ft_putchar(format[i]);
        i++;
	}
    va_end(args);
    return (0);
}

int main (void)
{
    char *nine = "nine";
	ft_printf("hello %s", nine);
	return (0);
}