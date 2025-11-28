/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:29 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/28 13:07:14 by kkweon           ###   ########.fr       */
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
    if (c == 'c')
        va = ft_putchar(va_arg(args, int));
    if (c == 'i' || c == 'd')
        va = ft_putnbr(va_arg(args, int));
    if (c == 'u')
        va = ft_putunbr(va_arg(args, unsigned int));
    if (c == '%')
        va = ft_putchar('%');
    if (c == 'p')
    {
        va = ft_putstr("0x");
        va = ft_putstr(va_arg(args, char *));
    }
        
    // if (c == 'x')
    // if (c == 'X')
    
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
            {
                data_type = type_specifier(args, format[i + 1]);
                i++;
            }
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
    char c = 'c';
    int nbr = 123;
    unsigned int unbr = -123;
    ft_printf("\n");
    ft_printf("[FT_PRINTF RESULT]\n");
    ft_printf("string: %s\n", "this is string");
    ft_printf("character: %c\n", 'c');
    ft_printf("integer: %i\n", 42);
    ft_printf("decimal: %d\n", 42);
    ft_printf("unsigned int for -1000: %u\n", -1000);
    ft_printf("percentage sign: %%\n");
    ft_printf("memory address: %p\n", &c);
	ft_printf("all together: %s, %c, %i, %d, %u %%\n", nine, c, nbr, nbr, unbr);
    ft_printf("\n");
    printf("[STANDARD PRINTF RESULT]\n");
    printf("[ft_printf function tests]\n");
    printf("string: %s\n", "this is string");
    printf("character: %c\n", 'c');
    printf("integer: %i\n", 42);
    printf("decimal: %d\n", 42);
    printf("unsigned int for -1000: %u\n", -1000);
    printf("percentage sign: %%\n");
    printf("memory address: %p\n", &c);
	printf("all together: %s, %c, %i, %d, %u %%\n", nine, c, nbr, nbr, unbr);
    printf("\n");
    
    printf("official printf for hex lower: %x\n", 123123);
    printf("official printf for hex upper: %X\n", 123123);
    return (0);
}