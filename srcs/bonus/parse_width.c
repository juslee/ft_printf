/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:18:12 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 12:37:46 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

int	parse_width(const char **format, va_list *args)
{
	int	width;

	width = 0;
	if (**format == '*')
	{
		width = va_arg(*args, int);
		(*format)++;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			width = width * 10 + (**format - '0');
			(*format)++;
		}
	}
	return (width);
}
