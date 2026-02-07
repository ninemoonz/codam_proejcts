/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:29 by kkweon            #+#    #+#             */
/*   Updated: 2026/01/10 18:42:30 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_args(va_list *args, char c)
{
	if (c == 's')
        return (ft_putstr(va_arg(*args, char *)));
    else if (c == 'c')
        return(ft_putchar(va_arg(*args, int)));
    else if (c == 'i' || c == 'd')
        return(ft_putnbr(va_arg(*args, int)));
    else if (c == 'u')
        return(ft_putunbr(va_arg(*args, int)));
    else if (c == '%')
        return(ft_putchar('%'));
    else if (c == 'x')
        return(ft_puthex(va_arg(*args, int)));
    else if (c == 'X')
        return(ft_putuphex(va_arg(*args, int)));
    else if (c == 'p')
        return(ft_putptr(va_arg(*args, void *)));
    return (-1);
}

int ft_printf(const char *format, ...)
{
    va_list args; 
	int i;
    int str_len;

	va_start(args, format);
	i = 0;
    str_len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
        {
            str_len += print_args(&args, format[i + 1]);
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == '\0')
        {
            va_end(args);
            return (-1);
        }
        else
            str_len += ft_putchar(format[i]);
        i++;
	}
    va_end(args);
    return (str_len);
}
