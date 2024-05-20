/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:02:49 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 10:01:20 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr.c
 * @brief The function that prints an integer to stdout
 */

#include <stdlib.h>
#include "ft_printf.h"

/**
 * @brief Print an integer to stdout
 * @param n The integer to be printed
 * @return int The number of characters printed
 */
int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}
