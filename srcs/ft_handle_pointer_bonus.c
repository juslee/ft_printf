/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:21:33 by welee             #+#    #+#             */
/*   Updated: 2024/05/26 17:21:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_pointer_bonus.c
 * @brief Handle the pointer specifier
 */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

/**
 * @brief Handle the pointer specifier
 * @param ptr The pointer to be printed
 * @param format_info The format information
 * @return int The number of characters printed
 * @note The format information is as follows:
 * ['-' | '0'][width][p]
 */
int	ft_handle_pointer(void *ptr, t_format_info format_info)
{
	int				len;

	len = ft_ptrlen(ptr);
	if (!format_info.left_align && format_info.width > len)
	{
		if (format_info.zero_padded)
			ft_putstr("0x");
		ft_print_padding(format_info.width,
			len, format_info.zero_padded);
		if (!format_info.zero_padded)
			ft_putstr("0x");
	}
	else
		ft_putstr("0x");
	if (ptr == 0)
		ft_putchar('0');
	else
		ft_puthex((long)ptr, 0);
	if (format_info.left_align && format_info.width > len)
		ft_print_padding(format_info.width, len, 0);
	if (format_info.width > len)
		return (format_info.width);
	return (len);
}
