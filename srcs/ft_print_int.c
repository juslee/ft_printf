/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:23:08 by welee             #+#    #+#             */
/*   Updated: 2024/05/07 15:56:15 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base, int is_upper)
{
	char	*str;
	char	*hex;
	int		len;
	int		sign;

	hex = ft_ternary(is_upper, "0123456789ABCDEF", "0123456789abcdef");
	sign = n < 0;
	len = ft_ternary(sign, 2, 1);
	n /= base;
	while (n)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	n = ft_ternary(sign, -n, n);
	while (len--)
	{
		str[len] = hex[n % base];
		n /= base;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

int	ft_print_int_base(int n, int base, int is_upper)
{
	int		len;
	char	*str;

	len = 0;
	str = ft_itoa_base(n, base, is_upper);
	if (str)
	{
		len = ft_putstr(str);
		free(str);
	}
	return (len);
}

int	ft_print_int(int n)
{
	return (ft_print_int_base(n, 10, 0));
}
