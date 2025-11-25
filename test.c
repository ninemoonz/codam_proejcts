/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkweon <kkweon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:53:09 by kkweon            #+#    #+#             */
/*   Updated: 2025/11/25 16:46:06 by kkweon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int sum(int nitem, ...)
{
	int i;
	int res;
	va_list args;

	i = 0;
	res = 0;
	va_start(args, nitem);
	while(i < nitem)
	{
		res += va_arg(args, int);
		i++;
	}
	va_end(args);
	return (res);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
}

int	main(void)
{

	printf("%d\n", sum(3, 3, 3, 3, 3));
	ft_printf("")
	return (0);
}
