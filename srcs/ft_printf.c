/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:24:49 by welee             #+#    #+#             */
/*   Updated: 2024/05/09 20:46:41 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief The main file for the ft_printf project
 */

#include "libft.h"
#include "ft_printf.h"

int	ft_parse_format(const char **format, va_list args)
{
	int	count;

	count = 0;
	if (**format == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (**format == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (**format == 'p')
		count += ft_print_pointer(va_arg(args, unsigned long long));
	else if (**format == 'd' || **format == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (**format == 'u')
		count += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (**format == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (**format == '%')
		count += ft_print_char('%');
	else
	{
		ft_putchar('%');
		ft_putchar(**format);
		count += 2;
	}
	return (count);
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
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_parse_format(&format, args);
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

