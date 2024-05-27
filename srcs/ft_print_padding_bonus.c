/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:13:42 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 14:47:56 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_print_padding_bonus.c
 * @brief The function that prints padding characters
 */

#include "ft_printf.h"

/**
 * @brief Print padding characters
 * @param width The width of the padding
 * @param len The length of the string
 * @param zero_pad Whether to zero pad
 */
int	ft_print_padding(int width, int len, int zero_pad)
{
	char	pad_char;
	int		i;

	if (zero_pad)
		pad_char = '0';
	else
		pad_char = ' ';
	i = 0;
	while (i < width - len)
	{
		ft_putchar(pad_char);
		i++;
	}
	return (i);
}
