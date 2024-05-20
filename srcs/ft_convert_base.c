/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:47:08 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 09:47:28 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_convert_base.c
 * @brief Convert a number to a string in a given base
 */

/**
 * @brief Convert a number to a string in a given base
 * @param str The string to store the number in
 * @param n The number to convert
 * @param len The length of the number
 * @param base The base to convert the number to
 */
void	ft_convert_base(char *str, long long n, int len, int base)
{
	char	*digits;

	digits = "0123456789abcdef";
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = digits[n % base];
		n /= base;
	}
}
