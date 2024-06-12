/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:16:10 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 12:37:59 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

int	parse_precision(const char **format, va_list *args)
{
	int	precision;

	precision = -1;
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			precision = va_arg(*args, int);
			(*format)++;
		}
		else
		{
			precision = 0;
			while (**format >= '0' && **format <= '9')
			{
				precision = precision * 10 + (**format - '0');
				(*format)++;
			}
		}
	}
	return (precision);
}
