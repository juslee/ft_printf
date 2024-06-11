/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:45:00 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 21:48:52 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_format_bonus.c
 * @brief Handle the specifier and print the formatted string
 */

#include "ft_printf_util.h"
#include "ft_printf_util_bonus.h"
#include <stdio.h>

/**
 * @brief Handle the specifier and print the formatted string
 * @param format The specifier to be handled
 * @param args The arguments to be formatted
 * @return int The number of characters printed
 */
int	ft_handle_format(const char **format, va_list *args)
{
	t_format_info	format_info;

	format_info = ft_parse_format(format);
	if (format_info.specifier == SPEC_CHAR)
		return (ft_handle_chr(va_arg(*args, int), format_info));
	else if (format_info.specifier == SPEC_STRING)
		return (ft_handle_str(va_arg(*args, char *), format_info));
	else if (format_info.specifier == SPEC_POINTER)
		return (ft_handle_ptr(va_arg(*args, void *), format_info));
	else if (format_info.specifier == SPEC_DECIMAL
		|| format_info.specifier == SPEC_INTEGER)
		return (ft_handle_nbr(va_arg(*args, int), format_info));
	else if (format_info.specifier == SPEC_UNSIGNED)
		return (ft_handle_unbr(va_arg(*args, unsigned int), format_info));
	else if (format_info.specifier == SPEC_HEX_LOW)
		return (ft_handle_hex(va_arg(*args, unsigned int), format_info,
				HEX_LOWER));
	else if (format_info.specifier == SPEC_HEX_UP)
		return (ft_handle_hex(va_arg(*args, unsigned int), format_info,
				HEX_UPPER));
	else if (format_info.specifier == SPEC_PERCENT)
		return (ft_putchar('%'));
	return (0);
}
