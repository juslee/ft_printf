/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:33:39 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 11:24:57 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_ptrlen.c
 * @brief The function that returns the length of a pointer
 */

#include <stddef.h>

/**
 * @brief Get the length of a pointer
 * @param ptr The pointer
 * @return size_t The length of the pointer
 */
size_t	ft_ptrlen(void *ptr)
{
	unsigned long long	address;
	size_t				len;

	len = 2;
	address = (long)ptr;
	while (address)
	{
		len++;
		address /= 16;
	}
	return (len);
}
