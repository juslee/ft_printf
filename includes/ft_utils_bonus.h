/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:04:44 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 13:06:57 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_format
{
	int	left_align;
	int	zero_pad;
	int	alt_form;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_format;

int		ft_strlen(char *str);
int		ft_nbrlen(int n);
int		ft_unbrlen(unsigned int n);
int		ft_hexlen(unsigned long n);

void	init_format(t_format *fmt);
int		parse_flags(const char **format, t_format *fmt);
int		parse_width(const char **format, va_list *args);
int		parse_precision(const char **format, va_list *args);

int		handle_char(t_format *fmt, char c);
int		handle_str(t_format *fmt, char *str);
int		handle_ptr(t_format *fmt, void *ptr);
int		handle_nbr(t_format *fmt, int n);
int		handle_unbr(t_format *fmt, unsigned int n);
int		handle_hex(t_format *fmt, unsigned int n, int uppercase);
int		handle_format(const char **format, va_list *args);
#endif
