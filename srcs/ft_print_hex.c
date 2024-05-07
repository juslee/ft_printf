/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:36:50 by welee             #+#    #+#             */
/*   Updated: 2024/05/07 15:53:51 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long n, int is_upper)
{
	int		ret;

	ret = 0;
	if (n >= 16)
		ret += ft_print_hex(n / 16, is_upper);
	if (n % 16 < 10)
		ret += ft_putchar(n % 16 + '0');
	else
		ret += ft_putchar(n % 16 - 10 + ft_ternary(is_upper, 'A', 'a'));
	return (ret);
}
