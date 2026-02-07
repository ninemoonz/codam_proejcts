/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koodal <koodal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:29:25 by koodal            #+#    #+#             */
/*   Updated: 2026/01/10 18:57:30 by koodal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main (void)
{
    printf("[STANDARD PRINTF]\n");
    int num = printf("%d\n", -12345);
    printf("std return: %d\n", num);
    printf("[42 PRINTF]\n");
    int num_ft = ft_printf("%d\n", -12345);
    ft_printf("ft return: %d\n", num_ft);
    return (0);
}