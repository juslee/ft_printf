/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_chr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:15:25 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 21:09:33 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_char_bonus.c
 * @brief Handle the character specifier
 */

#include "ft_printf_util.h"
#include "ft_printf_util_bonus.h"

/**
 * @brief Handle the character specifier
 * @param c The character to be printed
 * @param format_info The format information
 * @return int The number of characters printed
 * @note The format information is as follows:
 * ['-'][width][c]
 */
int	ft_handle_chr(int c, t_format_info format_info)
{
	if (!format_info.left_align && format_info.width > 1)
		ft_print_padding(format_info.width, 1, format_info.zero_padded);
	ft_putchar(c);
	if (format_info.left_align && format_info.width > 1)
		ft_print_padding(format_info.width, 1, 0);
	if (format_info.width > 1)
		return (format_info.width);
	return (1);
}
