/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:10:05 by welee             #+#    #+#             */
/*   Updated: 2024/05/22 09:59:11 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_puthex.c
 * @brief The function that prints a hexadecimal number to stdout
 */

#include "ft_printf.h"

/**
 * @brief Print a hexadecimal number to stdout
 * @param n The number to be printed
 * @param uppercase Whether to print the number in uppercase
 * @return int The number of characters printed
 */
int	ft_puthex(unsigned long long num, int is_upper)
{
	char	*hex_digits;
	char	buffer[17];
	int		len;
	int		i;

	if (is_upper)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	len = 0;
	if (num == 0)
		return (ft_putchar('0'));
	while (num)
	{
		buffer[len++] = hex_digits[num % 16];
		num /= 16;
	}
	i = len;
	while (i--)
		ft_putchar(buffer[i]);
	return (len);
}
