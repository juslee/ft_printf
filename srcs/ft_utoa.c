/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:05:27 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 19:02:35 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_utoa.c
 * @brief The function that converts an unsigned integer to a string
 */

#include <stdlib.h>
#include "ft_printf_util.h"

/**
 * @brief Convert an unsigned integer to a string
 * @param n The unsigned integer to convert
 * @return The string representation of the unsigned integer
 */
char	*ft_utoa(unsigned int n)
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
