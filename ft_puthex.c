/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:59:22 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/28 13:17:42 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void ft_puthex(int n)
{
    char *hex_letter = "0123456789abcdef";
    int hex_index;

    while (n != 0)
    {
        hex_index = n / 16;
        ft_putchar(hex_letter[hex_index]);
    }
}

int main (void)
{
    ft_puthex(30);
    return (0);
}