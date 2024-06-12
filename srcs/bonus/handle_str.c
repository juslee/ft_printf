/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:49:42 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 13:45:12 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_utils_bonus.h"

int	handle_str(t_format *fmt, char *str)
{
	int	len;
	int	str_len;

	len = 0;
	str_len = ft_strlen(str);
	if (fmt->precision >= 0 && str_len > fmt->precision)
		str_len = fmt->precision;
	if (fmt->left_align)
	{
		len += ft_putstr(str);
		while (fmt->width-- > str_len)
			len += ft_putchar(' ');
	}
	else
	{
		while (fmt->width-- > str_len)
			len += ft_putchar(' ');
		len += ft_putstr(str);
	}
	return (len);
}
