/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:24:49 by welee             #+#    #+#             */
/*   Updated: 2024/06/13 09:04:47 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_vprintf.c
 * @brief The function that prints a formatted string to stdout
 */

#include "ft_printf.h"

/**
 * @brief Print formatted string to stdout
 * @param format The format string
 * @param args The arguments to be formatted
 * @return int The number of characters printed
 */
int	ft_vprintf(const char *format, va_list args)
{
	int	len;

	len = 0;
	while (format && *format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			len += handle_format(&format, args);
		}
		else
		{
			len += ft_putchar(*format);
		}
		format++;
	}
	return (len);
}
