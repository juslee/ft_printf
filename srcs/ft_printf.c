/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:24:49 by welee             #+#    #+#             */
/*   Updated: 2024/05/26 11:24:48 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief The main file for the ft_printf project
 */

#include <stdarg.h>
#include "ft_printf.h"

/**
 * @brief Print formatted string to stdout
 * @param format The format string
 * @param args The arguments to be formatted
 * @return int The number of characters printed
 */
int	ft_vprintf(const char *format, va_list args)
{
	int		len;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_handle_format(&format, &args);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	return (len);
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
	int		len;

	va_start(args, format);
	len = ft_vprintf(format, args);
	va_end(args);
	return (len);
}
