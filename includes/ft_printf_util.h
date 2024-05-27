/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:52:13 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 18:53:41 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H
# include <stdarg.h>
# include <stddef.h>

# define SPEC_CHAR 'c'
# define SPEC_STRING 's'
# define SPEC_POINTER 'p'
# define SPEC_DECIMAL 'd'
# define SPEC_INTEGER 'i'
# define SPEC_UNSIGNED 'u'
# define SPEC_HEX_LOW 'x'
# define SPEC_HEX_UP 'X'
# define SPEC_PERCENT '%'

# define HEX_LOWER 0
# define HEX_UPPER 1

int		ft_vprintf(const char *format, va_list args);
int		ft_handle_format(const char **format, va_list *args);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned long long n, int is_upper);
int		ft_putptr(void *ptr);

char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
void	ft_convert_base(char *str, long long n, int len, int base);
int		ft_numlen_base(long long n, int base);
size_t	ft_strlen(const char *s);
size_t	ft_ptrlen(void *ptr);
#endif