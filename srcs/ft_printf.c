/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:24:49 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 10:05:49 by welee            ###   ########.fr       */
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
static int	handle_specifier(char specifier, va_list args)
{
	if (specifier == SPEC_CHAR)
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == SPEC_STRING)
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == SPEC_POINTER)
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (specifier == SPEC_DECIMAL || specifier == SPEC_INTEGER)
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == SPEC_UNSIGNED)
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (specifier == SPEC_HEX_LOW)
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (specifier == SPEC_HEX_UP)
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (specifier == SPEC_PERCENT)
		return (ft_putchar('%'));
	return (0);
}

/**
 * @brief Print formatted string to stdout
 * @param format The format string
 * @param ... The arguments to be formatted
 * @return int The number of characters printed
 */
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += handle_specifier(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

