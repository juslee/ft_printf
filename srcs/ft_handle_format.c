/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:24:49 by welee             #+#    #+#             */
/*   Updated: 2024/05/26 11:24:33 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief The main file for the ft_printf project
 */

#include <stdarg.h>
#include "ft_printf.h"

/**
 * @brief Handle the specifier and print the formatted string
 * @param specifier The specifier to be handled
 * @param args The arguments to be formatted
 * @return int The number of characters printed
 */
int	ft_handle_format(const char **format, va_list *args)
{
	if (**format == SPEC_CHAR)
		return (ft_putchar(va_arg(*args, int)));
	else if (**format == SPEC_STRING)
		return (ft_putstr(va_arg(*args, char *)));
	else if (**format == SPEC_POINTER)
		return (ft_putptr(va_arg(*args, void *)));
	else if (**format == SPEC_DECIMAL || **format == SPEC_INTEGER)
		return (ft_putnbr(va_arg(*args, int)));
	else if (**format == SPEC_UNSIGNED)
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (**format == SPEC_HEX_LOW)
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (**format == SPEC_HEX_UP)
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (**format == SPEC_PERCENT)
		return (ft_putchar('%'));
	return (0);
}
