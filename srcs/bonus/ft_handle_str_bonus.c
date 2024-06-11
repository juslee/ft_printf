/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:19:45 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 21:17:54 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_string_bonus.c
 * @brief Handle the string specifier
 */

#include "ft_printf_util.h"
#include "ft_printf_util_bonus.h"

/**
 * @brief Print a string
 * @param str The string to be printed
 * @param len The length of the string
 * @return int The number of characters printed
 */
int	ft_print_string(char *str, int len)
{
	int	printed_chars;

	printed_chars = 0;
	if (str == NULL)
		printed_chars += ft_putstr("(null)");
	else
	{
		while (*str && len--)
		{
			ft_putchar(*str++);
			printed_chars++;
		}
	}
	return (printed_chars);
}

/**
 * @brief Adjust the length of the string
 * @param str The string to be adjusted
 * @param format_info The format information
 * @return int The adjusted length
 */
int	ft_adjust_length(char *str, t_format_info format_info)
{
	int	len;

	if (!str)
		len = 6;
	else
		len = ft_strlen(str);
	if (format_info.precision >= 0 && format_info.precision < len)
		len = format_info.precision;
	return (len);
}

/**
 * @brief Handle the string specifier
 * @param str The string to be printed
 * @param format_info The format information
 * @return int The number of characters printed
 * @note The format information is as follows:
 * [‘-‘][width][precision][s]
 */
int	ft_handle_str(char *str, t_format_info format_info)
{
	int	len;
	int	printed_chars;

	printed_chars = 0;
	len = ft_adjust_length(str, format_info);
	if (!format_info.left_align && format_info.width > len)
		printed_chars += ft_print_padding(format_info.width,
				len, format_info.zero_padded);
	printed_chars += ft_print_string(str, len);
	if (format_info.left_align && format_info.width > len)
		printed_chars += ft_print_padding(format_info.width, len, 0);
	return (printed_chars);
}
