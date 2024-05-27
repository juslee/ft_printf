/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:11:45 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 19:15:25 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putptr.c
 * @brief The function that prints a pointer to stdout
 */

#include "ft_printf_util.h"

/**
 * @brief Print a pointer to stdout
 * @param ptr The pointer to be printed
 * @return int The number of characters printed
 */
int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	address;

	len = 0;
	address = (long)ptr;
	len += ft_putstr("0x");
	len += ft_puthex(address, 0);
	return (len);
}
