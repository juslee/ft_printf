/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:59:41 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 19:02:20 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr.c
 * @brief The function that prints a string to stdout
 */

#include "ft_printf_util.h"

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
	while (*str)
	{
		ft_putchar(*str);
		str++;
		len++;
	}
	return (len);
}
