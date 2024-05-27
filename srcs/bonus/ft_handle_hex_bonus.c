/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:03:48 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 18:57:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_util.h"
#include "ft_printf_util_bonus.h"

static void	handle_hex_prefix(t_format_info format_info, int is_upper)
{
	if (format_info.alternate_form)
	{
		if (is_upper)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
}

static void	handle_sign_and_padding(t_format_info format_info, int len,
	int is_upper)
{
	if (format_info.zero_padded)
	{
		handle_hex_prefix(format_info, is_upper);
		ft_print_padding(format_info.width, len, 1);
	}
	else
	{
		ft_print_padding(format_info.width, len, 0);
		handle_hex_prefix(format_info, is_upper);
	}
}

static void	handle_left_padding(t_format_info format_info, int len)
{
	if (format_info.width > len)
		ft_print_padding(format_info.width, len, 0);
}

/**
 * @brief Handle the hexadecimal specifier
 * @param num The number to be printed
 * @param format_info The format information
 * @param is_upper Whether the output should be in uppercase
 * @return int The number of characters printed
 * @note The format information is as follows:
 * ['#' | '-' | '0' | ' ' | '+'][width][X | x]
 */
int	ft_handle_hex(unsigned long long num, t_format_info format_info,
	int is_upper)
{
	int	len;
	int	total_len;

	len = ft_numlen_base(num, 16);
	if (format_info.alternate_form && num != 0)
		len += 2;
	if (format_info.width > len)
		total_len = format_info.width;
	else
		total_len = len;
	if (format_info.left_align)
	{
		handle_hex_prefix(format_info, is_upper);
		ft_puthex(num, is_upper);
		handle_left_padding(format_info, len);
	}
	else
	{
		handle_sign_and_padding(format_info, len, is_upper);
		ft_puthex(num, is_upper);
	}
	return (total_len);
}
