/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:19:00 by welee             #+#    #+#             */
/*   Updated: 2024/05/09 16:38:45 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_pointer(unsigned long long ptr)
{
	ft_putstr("0x");
	return (ft_strlen("0x") + ft_print_hex(ptr, 0));
}
