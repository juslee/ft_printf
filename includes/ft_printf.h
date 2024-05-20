/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:26:59 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 10:02:22 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPEC_CHAR 'c'
# define SPEC_STRING 's'
# define SPEC_POINTER 'p'
# define SPEC_DECIMAL 'd'
# define SPEC_INTEGER 'i'
# define SPEC_UNSIGNED 'u'
# define SPEC_HEX_LOW 'x'
# define SPEC_HEX_UP 'X'
# define SPEC_PERCENT '%'

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n, int uppercase);
int		ft_putptr(unsigned long ptr);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
void	ft_convert_base(char *str, long long n, int len, int base);
int		ft_numlen_base(long long n, int base);
#endif
