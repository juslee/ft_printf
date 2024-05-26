/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:19:45 by welee             #+#    #+#             */
/*   Updated: 2024/05/26 17:20:19 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_string_bonus.c
 * @brief Handle the string specifier
 */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

/**
 * @brief Handle the string specifier
 * @param str The string to be printed
 * @param format_info The format information
 * @return int The number of characters printed
 * @note The format information is as follows:
 * ['-' | '0'][width][s]
 */
int	ft_handle_string(char *str, t_format_info format_info)
{
	int	len;

	len = ft_strlen(str);
	if (!format_info.left_align && format_info.width > len)
		ft_print_padding(format_info.width, len, format_info.zero_padded);
	ft_putstr(str);
	if (format_info.left_align && format_info.width > len)
		ft_print_padding(format_info.width, len, 0);
	if (format_info.width > len)
		return (format_info.width);
	return (len);
}
