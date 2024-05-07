/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:26:59 by welee             #+#    #+#             */
/*   Updated: 2024/05/07 16:55:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_parse_format(const char **format, va_list args);
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_pointer(unsigned long long n);
int	ft_print_int(int n);
int	ft_print_unsigned_int(unsigned int n);
int	ft_print_hex(unsigned long long n, int is_upper);
#endif
