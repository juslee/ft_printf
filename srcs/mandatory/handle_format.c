/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:24:49 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 09:41:02 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief The main file for the ft_printf project
 */

#include "ft_utils.h"

/**
 * @brief Handle the specifier and print the formatted string
 * @param specifier The specifier to be handled
 * @param args The arguments to be formatted
 * @return int The number of characters printed
 */
int	handle_format(char specifier, va_list *args)
	{
	if (specifier == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
