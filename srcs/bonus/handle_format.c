/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:24:49 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 14:38:46 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief The main file for the ft_printf project
 */

#include "ft_utils_bonus.h"

/**
 * @brief Handle the specifier and print the formatted string
 * @param specifier The specifier to be handled
 * @param args The arguments to be formatted
 * @return int The number of characters printed
 */
int	handle_format(const char **format, va_list *args)
{
	t_format	fmt;
	char		specifier;

	init_format(&fmt);
	parse_flags(format, &fmt);
	fmt.width = parse_width(format, args);
	fmt.precision = parse_precision(format, args);
	specifier = **format;
	if (specifier == 'c')
		return (handle_char(&fmt, va_arg(*args, int)));
	else if (specifier == 's')
		return (handle_str(&fmt, va_arg(*args, char *)));
	else if (specifier == 'p')
		return (handle_ptr(&fmt, va_arg(*args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_nbr(&fmt, va_arg(*args, int)));
	else if (specifier == 'u')
		return (handle_unbr(&fmt, va_arg(*args, unsigned int)));
	else if (specifier == 'x')
		return (handle_hex(&fmt, va_arg(*args, unsigned int), 0));
	else if (specifier == 'X')
		return (handle_hex(&fmt, va_arg(*args, unsigned int), 1));
	else if (specifier == '%')
		return (handle_char(&fmt, '%'));
	return (0);
}
