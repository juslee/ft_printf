/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:07:24 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 13:43:31 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_utils_bonus.h"

int	handle_ptr(t_format *fmt, void *ptr)
{
	int				len;
	unsigned long	addr;

	len = 0;
	addr = (unsigned long)ptr;
	if (fmt->left_align)
	{
		len += ft_putstr("0x");
		len += ft_puthex(addr, 0);
		while (fmt->width-- > (int)(ft_hexlen(addr) + 2))
			len += ft_putchar(' ');
	}
	else
	{
		while (fmt->width-- > (int)(ft_hexlen(addr) + 2))
			len += ft_putchar(' ');
		len += ft_putstr("0x");
		len += ft_puthex(addr, 0);
	}
	return (len);
}
