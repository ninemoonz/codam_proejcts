/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:49:04 by koodal            #+#    #+#             */
/*   Updated: 2025/08/01 17:51:21 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        i++;
    }
    return (i);
}

void ft_putnbr_base(int nbr, char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (base[i] == '+' || base[i] == '-')
            return;
        i++;
    }

    if (i < 2)
        return;

    // if (doubleChar(base))
    //     return;

    if (nbr < 0)
    {
        nbr = -nbr;
        write(1, "-", 1);
    }
    int strlen;

    strlen = ft_strlen(base);
    if (nbr > strlen)
    {
        ft_putnbr_base(nbr / strlen, base);
    }

    char baseSymbol;

    baseSymbol = base[nbr % strlen];
    while (*base != baseSymbol)
    {
        base++;
    }
    printf("%c", *base);
}

int main(void)
{
    int nbr;
    char decimal[] = "0123456789";
    char binary[] = "10";
    char hex[] = "0123456789abcdef";
    char octal[] = "poneyvif";

    nbr = 42;
    ft_putnbr_base(nbr, binary);
    return (0);
}