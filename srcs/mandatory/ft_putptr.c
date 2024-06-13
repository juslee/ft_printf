/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:11:45 by welee             #+#    #+#             */
/*   Updated: 2024/06/13 09:26:35 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putptr.c
 * @brief The function that prints a pointer to stdout
 */

#include "ft_utils.h"

/**
 * @brief Print a pointer to stdout
 * @param ptr The pointer to be printed
 * @return int The number of characters printed
 */
int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)ptr;
	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex(addr, 0);
	return (len);
}
