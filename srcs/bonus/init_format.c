/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:22:00 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 12:22:39 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

void	init_format(t_format *fmt)
{
	fmt->left_align = 0;
	fmt->zero_pad = 0;
	fmt->alt_form = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->width = 0;
	fmt->precision = -1;
}
