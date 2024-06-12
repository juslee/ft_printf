/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:07:16 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 08:42:42 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putunbr.c
 * @brief The function that prints an unsigned integer to stdout
 */

#include "ft_utils.h"

/**
 * @brief Print an unsigned integer to stdout
 * @param n The unsigned integer to be printed
 * @return int The number of characters printed
 */
int	ft_putunbr(unsigned int n)
{
	char	buffer[11];
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		len += ft_putchar(buffer[--i]);
	return (len);
}
