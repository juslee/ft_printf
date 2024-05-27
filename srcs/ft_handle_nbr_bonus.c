/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:23:46 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 09:10:28 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_int_bonus.c
 * @brief Handle the integer specifier
 */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	int		is_negative;

	str = ft_itoa(n);  // Convert the number to a string
	len = ft_strlen(str);
	is_negative = (n < 0);
	total_len = 0;

	if (!format_info.left_align && format_info.width > len)
		ft_print_padding(format_info.width, len, format_info.zero_padded);

	if (is_negative)
		total_len += ft_putchar('-');
	else if (format_info.show_sign)
		total_len += ft_putchar('+');
	else if (format_info.space)
		total_len += ft_putchar(' ');

	total_len += ft_putstr(str);

	if (format_info.left_align && format_info.width > len)
		ft_print_padding(format_info.width, len, 0);

	free(str);
	return (total_len + (format_info.width > len ? format_info.width - len : 0));
}
