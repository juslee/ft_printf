/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:07:16 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 10:08:17 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putunbr.c
 * @brief The function that prints an unsigned integer to stdout
 */

#include <stdlib.h>
#include "ft_printf.h"

/**
 * @brief Print an unsigned integer to stdout
 * @param n The unsigned integer to be printed
 * @return int The number of characters printed
 */
int	ft_putunbr(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}
