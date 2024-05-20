/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:10:05 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 10:05:31 by welee            ###   ########.fr       */
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
int	ft_puthex(unsigned int n, int uppercase)
{
	int		len;
	char	*hex;

	len = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
	{
		len += ft_puthex(n / 16, uppercase);
		n %= 16;
	}
	ft_putchar(hex[n]);
	return (++len);
}
