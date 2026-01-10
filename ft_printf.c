/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:29 by kkweon            #+#    #+#             */
/*   Updated: 2025/12/03 17:36:37 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_args(va_list *args, char c)
{
	int	va;

	va = 0;
    if (c == 's')
        va = ft_putstr(va_arg(*args, char *));
    else if (c == 'c')
        va = ft_putchar(va_arg(*args, int));
    else if (c == 'i' || c == 'd')
        va = ft_putnbr(va_arg(*args, int));
    else if (c == 'u')
        va = ft_putunbr(va_arg(*args, int));
    else if (c == '%')
        va = ft_putchar('%');
    else if (c == 'x')
        va = ft_puthex(va_arg(*args, int));
    else if (c == 'X')
        va = ft_putuphex(va_arg(*args, int));
    else if (c == 'p')
        va = ft_putptr(va_arg(*args, void *));
    return (va);
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
		if (format[i] == '%')
        {
            if (format[i + 1] != '\0')
            {
                str_len += print_args(&args, format[i + 1]);
                i++;
            }
        }
        else
            str_len += ft_putchar(format[i]);
        i++;
	}
    va_end(args);
    return (str_len);
}

int main (void)
{
    int what;

    what = 10;
    ft_printf("hello\n");
    ft_printf("number: %d\n", what);
    ft_printf("char: %c\n", 'A');
    ft_printf("hello %s %c\n", "world", 'a');
    return (0);
}