/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:58:32 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 08:39:37 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putchar.c
 * @brief The function that prints a character to stdout
 */

#include "ft_utils.h"

/**
 * @brief Print a character to stdout
 * @param c The character to be printed
 * @return int The number of characters printed
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
