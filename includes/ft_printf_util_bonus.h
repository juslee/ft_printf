/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:10:59 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 21:15:03 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_BONUS_H
# define FT_PRINTF_UTIL_BONUS_H

# define FLAG_ALTERNATE_FORM '#'
# define FLAG_ZERO_PADDED '0'
# define FLAG_LEFT_ALIGN '-'
# define FLAG_SPACE ' '
# define FLAG_SHOW_SIGN '+'

typedef struct s_format_info
{
	int		alternate_form;
	int		zero_padded;
	int		left_align;
	int		space;
	int		show_sign;
	int		width;
	int		precision;
	char	specifier;
}	t_format_info;

t_format_info	ft_parse_format(const char **format);
t_format_info	ft_init_format_info(void);
void			ft_parse_flags(const char **format, t_format_info *format_info);
void			ft_parse_width(const char **format, t_format_info *format_info);
void			ft_parse_specifier(const char **format,
					t_format_info *format_info);

int				ft_print_padding(int width, int len, int zero_pad);

int				ft_handle_chr(int c, t_format_info format_info);
int				ft_handle_str(char *str, t_format_info format_info);
int				ft_handle_ptr(void *ptr, t_format_info format_info);
int				ft_handle_nbr(int n, t_format_info format_info);
int				ft_handle_unbr(unsigned int n, t_format_info format_info);
int				ft_handle_hex(unsigned long long n, t_format_info format_info,
					int is_upper);
#endif
