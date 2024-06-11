/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unbr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:15:43 by welee             #+#    #+#             */
/*   Updated: 2024/06/05 20:46:48 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_handle_unsigned_int.c
 * @brief Handle the unsigned integer specifier
 */

#include "ft_printf_util.h"
#include "ft_printf_util_bonus.h"
#include <stdlib.h>

/**
 * @brief Handle the unsigned integer specifier
 * @param num The unsigned integer to be printed
 * @param format_info The format information
 * @return int The number of characters printed
 * @note The format information is as follows:
 * ['-' | '0' | ' ' | '+'][width][u]
 */
int	ft_handle_unbr(unsigned int num, t_format_info format_info)
{
	int		len;
	char	*str;

	str = ft_utoa(num);
	len = ft_strlen(str);
	free(str);
	if (!format_info.left_align && format_info.width > len)
		ft_print_padding(format_info.width, len, format_info.zero_padded);
	ft_putunbr(num);
	if (format_info.left_align && format_info.width > len)
		ft_print_padding(format_info.width, len, 0);
	if (format_info.width > len)
		return (format_info.width);
	return (len);
}
