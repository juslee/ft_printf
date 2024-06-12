/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:57:59 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 13:43:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_utils_bonus.h"

int	handle_hex(t_format *fmt, unsigned int n, int uppercase)
{
	int	len;
	int	num_len;

	len = 0;
	num_len = ft_hexlen(n);
	if (fmt->alt_form && n != 0)
	{
		if (uppercase)
			len += ft_putstr("0X");
		else
			len += ft_putstr("0x");
	}
	if (fmt->left_align)
	{
		len += ft_puthex(n, uppercase);
		while (fmt->width-- > num_len)
			len += ft_putchar(' ');
	}
	else
	{
		while (fmt->width-- > num_len)
			len += ft_putchar(' ');
		len += ft_puthex(n, uppercase);
	}
	return (len);
}
