/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:52:30 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 13:43:16 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_utils_bonus.h"

int	handle_nbr(t_format *fmt, int n)
{
	int	len;
	int	num_len;

	len = 0;
	num_len = ft_nbrlen(n);
	if (fmt->plus && n >= 0)
		len += ft_putchar('+');
	else if (fmt->space && n >= 0)
		len += ft_putchar(' ');
	if (fmt->left_align)
	{
		len += ft_putnbr(n);
		while (fmt->width-- > num_len)
			len += ft_putchar(' ');
	}
	else
	{
		while (fmt->width-- > num_len)
			len += ft_putchar(' ');
		len += ft_putnbr(n);
	}
	return (len);
}
