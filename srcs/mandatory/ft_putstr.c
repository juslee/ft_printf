/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:59:41 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 08:54:39 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr.c
 * @brief The function that prints a string to stdout
 */

#include "ft_utils.h"

/**
 * @brief Print a string to stdout
 * @param str The string to be printed
 * @return int The number of characters printed
 */
int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}
