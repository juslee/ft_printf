/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:02:49 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 09:46:37 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr.c
 * @brief The function that prints an integer to stdout
 */

#include "ft_utils.h"

/**
 * @brief Print an integer to stdout
 * @param n The integer to be printed
 * @return int The number of characters printed
 */
int	ft_putnbr(int n)
{
	char			buffer[12];
	int				len;
	int				i;
	unsigned int	num;

	len = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		len += ft_putchar('-');
		num = -n;
	}
	else
		num = n;
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
		len += ft_putchar(buffer[--i]);
	return (len);
}
