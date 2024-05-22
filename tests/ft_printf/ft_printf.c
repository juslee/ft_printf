/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:07:08 by welee             #+#    #+#             */
/*   Updated: 2024/05/22 10:02:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	ft_printf("Hello, %s!\n", "world");
	ft_printf("Character: %c\n", 'A');
	ft_printf("Decimal: %d\n", 1234);
	ft_printf("Unsigned: %u\n", 1234);
	ft_printf("Hex lowercase: %x\n", 255);
	ft_printf("Hex uppercase: %X\n", 255);
	ft_printf("Pointer: %p\n", (void *)1234);
	ft_printf("Percent: %%\n");
	ft_printf("Character: %c %c\n", 'A', 'B');
	ft_printf("Pointer: %p %p\n", LONG_MIN, LONG_MAX);
	printf("Pointer: %p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf("Pointer: %p %p \n", 0, 0);
	printf("Pointer: %p %p \n", (void *)0, (void *)0);

	return (0);
}
