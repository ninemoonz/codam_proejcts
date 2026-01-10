/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:07:04 by kkweon            #+#    #+#             */
/*   Updated: 2026/01/10 18:26:27 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    unsigned long long addr;
    int count;
    if(!ptr || ptr == NULL)
        return (write(1, "(nil)", 5));
    count = 0;
    count += ft_putstr("0x");
    addr = (unsigned long long)ptr;
    count += ft_puthex(addr);
    return (count);
}
