/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:10:05 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 09:35:43 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_puthex.c
 * @brief The function that prints a hexadecimal number to stdout
 */

#include "ft_utils.h"

/**
 * @brief Print a hexadecimal number to stdout
 * @param n The hexadecimal number to be printed
 * @param uppercase Whether to print the number in uppercase
 * @return int The number of characters printed
 */
int	ft_puthex(unsigned long n, int uppercase)
{
	char	buffer[17];
	char	*base;
	int		len;
	int		i;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i > 0)
		len += ft_putchar(buffer[--i]);
	return (len);
}
