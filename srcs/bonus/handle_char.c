/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:47:51 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 13:42:40 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_utils_bonus.h"

int	handle_char(t_format *fmt, char c)
{
	int	len;

	len = 0;
	if (fmt->left_align)
	{
		len += ft_putchar(c);
		while (fmt->width-- > 1)
			len += ft_putchar(' ');
	}
	else
	{
		while (fmt->width-- > 1)
			len += ft_putchar(' ');
		len += ft_putchar(c);
	}
	return (len);
}
