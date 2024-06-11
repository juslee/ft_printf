/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:21:33 by welee             #+#    #+#             */
/*   Updated: 2024/06/06 00:23:06 by welee            ###   ########.fr       */
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
 * [ ‘-‘ | ‘0’ | ‘ ‘ | ‘+’ ][width][precision][p]
 */
#include <stdio.h>
int	ft_handle_ptr(void *ptr, t_format_info fi)
{
	unsigned long	addr;
	int				addr_len;
	int				len;
	int				printed_chars;
	char			addr_str[20];

	addr = (long)ptr;
	addr_len = ft_numlen_base(addr, 16);
	printf("%d\n", addr_len);
	len = addr_len + 2;
	printed_chars = 0;
	ft_convert_base(addr_str, addr, addr_len, 16);
	printf("%s\n", addr_str);
	addr_str[addr_len] = '\0';
	if (fi.precision > addr_len)
		len += (fi.precision - addr_len);
	if (fi.width > len && !fi.left_align && !fi.zero_padded)
		printed_chars += ft_print_padding(fi.width, len, 0);
	printed_chars += ft_putstr("0x");
	if (fi.width > len && !fi.left_align && fi.zero_padded)
		printed_chars += ft_print_padding(fi.width, len, 1);
	if (fi.precision > addr_len)
		printed_chars += ft_print_padding(fi.precision, addr_len, 1);
	printf("%s\n", addr);
	printed_chars += ft_puthex(addr, 0);
	if (fi.width > len && fi.left_align)
		printed_chars += ft_print_padding(fi.width, len, 0);
	return (printed_chars);
}
