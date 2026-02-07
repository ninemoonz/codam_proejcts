/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:30:03 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/27 16:42:47 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	unsigned int res;

	res = 0;

	if (n >= 10)
	{
		res = ft_putnbr(n / 10);
		res++;
		res = ft_putnbr(n % 10);
		res++;
	}
	else
	{
		res = ft_putchar(n + '0');
		res++;
	}
	return (res);
}
