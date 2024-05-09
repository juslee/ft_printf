/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:23:08 by welee             #+#    #+#             */
/*   Updated: 2024/05/09 16:33:01 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int n, int base, int is_upper)
{
	char	*str;
	char	*hex;
	int		len;
	int		sign;
	int		negative_n;

	hex = ft_ternary(is_upper, "0123456789ABCDEF", "0123456789abcdef");
	sign = n < 0;
	len = *(int *)ft_ternary(sign, (void *)2, (void *)1);
	n /= base;
	while (n)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	negative_n = -n;
	n = *(int *)ft_ternary(sign, &negative_n, &n);
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

	str = ft_itoa_base(n, base, is_upper);
	len = ft_strlen(str);
	if (str)
	{
		ft_putstr(str);
		free(str);
	}
	return (len);
}

int	ft_print_int(int n)
{
	return (ft_print_int_base(n, 10, 0));
}
