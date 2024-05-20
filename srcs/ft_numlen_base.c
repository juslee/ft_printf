/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:48:20 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 09:48:45 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_numlen_base.c
 * @brief Get the length of a number in a given base
 */

/**
 * @brief Get the length of a number in a given base
 * @param n The number to get the length of
 * @param base The base to get the length in
 * @return The length of the number in the given base
 */
int	ft_numlen_base(long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
