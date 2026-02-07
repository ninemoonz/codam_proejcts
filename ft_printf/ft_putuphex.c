/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:59:22 by kkweon            #+#    #+#             */
/*   Updated: 2026/01/10 17:24:20 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putuphex(unsigned int n)
{
    char *hex_letter = "0123456789ABCDEF";
    int hex_nbr;

    hex_nbr = 0;
    if (n >= 16)
        hex_nbr += ft_putuphex(n / 16);
    write(1, &hex_letter[n % 16], 1);
    hex_nbr++;
    return (hex_nbr);
}
