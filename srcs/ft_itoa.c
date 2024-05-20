/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:04:31 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 09:49:38 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 * @brief Convert an integer to a string
 */

#include <stdlib.h>
#include "ft_printf.h"

/**
 * @brief Convert an integer to a string
 * @param n The integer to convert
 * @return The string representation of the integer
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen_base(n, 10);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_convert_base(str, n, len, 10);
	return (str);
}
