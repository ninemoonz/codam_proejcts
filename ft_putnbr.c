/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:30:03 by kkweon            #+#    #+#             */
/*   Updated: 2026/01/10 18:56:28 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int res;

	res = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		res += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		res += ft_putnbr(n / 10);
		res += ft_putnbr(n % 10);
	}
	else
	{
		res += ft_putchar(n + '0');
	}
	return (res);
}
