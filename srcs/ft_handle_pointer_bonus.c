/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:21:33 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 18:57:42 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_pointer_bonus.c
 * @brief Handle the pointer specifier
 */

#include "ft_printf_util.h"
#include "ft_printf_util_bonus.h"

/**
 * @brief Handle the pointer specifier
 * @param ptr The pointer to be printed
 * @param fi The format information
 * @return int The number of characters printed
 * @note The format information is as follows:
 * ['-' | '0'][width][p]
 */
int	ft_handle_pointer(void *ptr, t_format_info fi)
{
	int		address_len;
	int		total_len;
	int		padded_len;

	if (ptr)
		address_len = ft_ptrlen(ptr) - 2;
	else
		address_len = 1;
	total_len = address_len + 2;
	padded_len = fi.width - total_len;
	if (!fi.left_align && (!fi.zero_padded || ptr == 0) && padded_len > 0)
		ft_print_padding(padded_len, 0, 0);
	ft_putstr("0x");
	if (!fi.left_align && fi.zero_padded && ptr != 0 && padded_len > 0)
		ft_print_padding(padded_len, 0, 1);
	if (ptr == 0)
		ft_putchar('0');
	else
		ft_puthex((unsigned long)ptr, 0);
	if (fi.left_align && padded_len > 0)
		ft_print_padding(padded_len, 0, 0);
	if (padded_len > 0)
		total_len += padded_len;
	return (total_len);
}
