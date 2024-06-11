/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:23:46 by welee             #+#    #+#             */
/*   Updated: 2024/06/05 20:44:32 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_int_bonus.c
 * @brief Handle the integer specifier
 */

#include "ft_printf_util.h"
#include "ft_printf_util_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Print the sign of the integer
 * @param n The integer
 * @param format_info The format information
 * @return int The number of characters printed
 */
static int	ft_print_sign(int n, t_format_info format_info)
{
	if (n < 0)
		return (ft_putchar('-'));
	else if (format_info.show_sign)
		return (ft_putchar('+'));
	else if (format_info.space)
		return (ft_putchar(' '));
	return (0);
}

/**
 * @brief Calculate the padded length
 * @param len The length of the integer
 * @param format_info The format information
 * @param is_negative Whether the integer is negative
 * @return int The padded length
 */
static int	ft_calc_padded_len(int len, t_format_info format_info,
	int is_negative)
{
	int	padded_len;

	padded_len = format_info.width - len;
	if (is_negative || format_info.show_sign || format_info.space)
		padded_len--;
	if (padded_len > 0)
		return (padded_len);
	return (0);
}

/**
 * @brief Handle the integer specifier
 * @param n The integer to be printed
 * @param format_info The format information
 * @return int The number of characters printed
 * @note The format information is as follows:
 * ['-' | '0' | ' ' | '+'][width][d | i]
 */
int	ft_handle_nbr(int n, t_format_info format_info)
{
	char	*str;
	int		len;
	int		total_len;
	int		padded_len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	total_len = 0;
	padded_len = ft_calc_padded_len(len, format_info, n < 0);
	if (!format_info.left_align && !format_info.zero_padded && padded_len > 0)
		ft_print_padding(padded_len, 0, format_info.zero_padded);
	total_len += ft_print_sign(n, format_info);
	if (!format_info.left_align && format_info.zero_padded && padded_len > 0)
		ft_print_padding(padded_len, 0, 1);
	if (n < 0)
		total_len += ft_putstr(str + 1);
	else
		total_len += ft_putstr(str);
	if (format_info.left_align && padded_len > 0)
		ft_print_padding(padded_len, 0, 0);
	free(str);
	if (padded_len > 0)
		return (total_len + padded_len);
	return (total_len);
}
