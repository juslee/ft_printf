/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:19:22 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 12:20:27 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

int	parse_flags(const char **format, t_format *fmt)
{
	int	parsed;

	parsed = 0;
	while (**format == '-' || **format == '0' || **format == '#'
		|| **format == ' ' || **format == '+')
	{
		if (**format == '-')
			fmt->left_align = 1;
		else if (**format == '0')
			fmt->zero_pad = 1;
		else if (**format == '#')
			fmt->alt_form = 1;
		else if (**format == ' ')
			fmt->space = 1;
		else if (**format == '+')
			fmt->plus = 1;
		(*format)++;
		parsed = 1;
	}
	return (parsed);
}
