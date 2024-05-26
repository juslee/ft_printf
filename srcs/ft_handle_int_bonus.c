/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:23:46 by welee             #+#    #+#             */
/*   Updated: 2024/05/26 17:53:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_int_bonus.c
 * @brief Handle the integer specifier
 */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

/**
 * @brief Get the sign of the number
 * @param num The number
 * @param format_info The format information
 * @return char The sign of the number
 */
static char	get_sign(int num, t_format_info format_info)
{
	if (num < 0)
		return ('-');
	if (format_info.show_sign)
		return ('+');
	if (format_info.space)
		return (' ');
	return (0);
}

/**
 * @brief Handle the sign and padding
 * @param sign The sign of the number
 * @param format_info The format information
 * @param pad_len The padding length
 */
static void	handle_sign_and_padding(char sign, t_format_info format_info,
	int pad_len)
{
	if (sign && !format_info.left_align && format_info.zero_padded)
		ft_putchar(sign);
	if (!format_info.left_align && format_info.width > pad_len)
	{
		if (format_info.zero_padded)
			ft_print_padding(format_info.width, pad_len, '0');
		else
			ft_print_padding(format_info.width, pad_len, ' ');
	}
	if (sign && !(format_info.zero_padded && !format_info.left_align))
		ft_putchar(sign);
}

/**
 * @brief Handle the left padding
 * @param format_info The format information
 * @param pad_len The padding length
 */
static void	handle_left_padding(t_format_info format_info, int pad_len)
{
	if (format_info.left_align && format_info.width > pad_len)
		ft_print_padding(format_info.width, pad_len, ' ');
}

/**
 * @brief Handle the integer specifier
 * @param n The integer to be printed
 * @param format_info The format information
 * @return int The number of characters printed
 * @note The format information is as follows:
 * ['-' | '0'][width][d | i]
 */
int	ft_handle_int(int num, t_format_info format_info)
{
	int		len;
	char	sign;
	int		total_len;

	len = ft_numlen_base(num, 10);
	sign = get_sign(num, format_info);
	if (sign)
		len++;
	if (format_info.width > len)
		total_len = format_info.width;
	else
		total_len = len;
	handle_sign_and_padding(sign, format_info, len);
	if (num < 0)
		ft_putnbr(-num);
	else
		ft_putnbr(num);
	handle_left_padding(format_info, len);
	return (total_len);
}
