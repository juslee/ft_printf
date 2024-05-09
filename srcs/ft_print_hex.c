/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:36:50 by welee             #+#    #+#             */
/*   Updated: 2024/05/09 16:44:14 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_hex(unsigned long long n, int is_upper)
{
	int		ret;

	ret = 0;
	if (n >= 16)
		ret += ft_print_hex(n / 16, is_upper);
	if (n % 16 < 10)
		ret += ft_print_char(n % 16 + '0');
	else
	{
		if (is_upper)
			ret += ft_print_char(n % 16 - 10 + 'A');
		else
			ret += ft_print_char(n % 16 - 10 + 'a');
	}
	return (ret);
}
