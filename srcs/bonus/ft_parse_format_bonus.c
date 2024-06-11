/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 01:23:53 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 21:01:10 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_parse_format_bonus.c
 * @brief The function to parse the format string
 */

#include "ft_printf_util.h"
#include "ft_printf_util_bonus.h"

/**
 * @brief Parse the flags from the format string
 * @param format The format string
 * @param format_info The format info struct to store the parsed flags
 */
void	ft_parse_flags(const char **format, t_format_info *format_info)
{
	while (**format == FLAG_ALTERNATE_FORM || **format == FLAG_ZERO_PADDED
		|| **format == FLAG_LEFT_ALIGN || **format == FLAG_SPACE
		|| **format == FLAG_SHOW_SIGN)
	{
		if (**format == FLAG_ALTERNATE_FORM)
			format_info->alternate_form = 1;
		else if (**format == FLAG_ZERO_PADDED)
			format_info->zero_padded = 1;
		else if (**format == FLAG_LEFT_ALIGN)
			format_info->left_align = 1;
		else if (**format == FLAG_SPACE)
			format_info->space = 1;
		else if (**format == FLAG_SHOW_SIGN)
			format_info->show_sign = 1;
		(*format)++;
	}
}

/**
 * @brief Parse the width from the format string
 * @param format The format string
 * @param format_info The format info struct to store the parsed width
 */
void	ft_parse_width(const char **format, t_format_info *format_info)
{
	while (**format >= '0' && **format <= '9')
	{
		format_info->width = format_info->width * 10 + (**format - '0');
		(*format)++;
	}
}

/**
 * @brief Parse the precision from the format string
 * @param format The format string
 * @param format_info The format info struct to store the parsed precision
 */
void	ft_parse_precision(const char **format, t_format_info *format_info)
{
	if (**format == '.')
	{
		format_info->precision = 0;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			format_info->precision = format_info->precision
				* 10 + (**format - '0');
			(*format)++;
		}
	}
}

/**
 * @brief Parse the specifier from the format string
 * @param format The format string
 * @param format_info The format info struct to store the parsed specifier
 */
void	ft_parse_specifier(const char **format, t_format_info *format_info)
{
	if (**format == SPEC_CHAR || **format == SPEC_STRING
		|| **format == SPEC_POINTER || **format == SPEC_DECIMAL
		|| **format == SPEC_INTEGER || **format == SPEC_UNSIGNED
		|| **format == SPEC_HEX_LOW || **format == SPEC_HEX_UP
		|| **format == SPEC_PERCENT)
	{
		format_info->specifier = **format;
	}
}

/**
 * @brief Parse the flags from the format string
 * @param format The format string
 * @return t_flags The parsed flags
 */
t_format_info	ft_parse_format(const char **format)
{
	t_format_info	format_info;

	format_info.alternate_form = 0;
	format_info.zero_padded = 0;
	format_info.left_align = 0;
	format_info.space = 0;
	format_info.show_sign = 0;
	format_info.width = 0;
	format_info.precision = -1;
	format_info.specifier = 0;
	ft_parse_flags(format, &format_info);
	ft_parse_width(format, &format_info);
	ft_parse_precision(format, &format_info);
	ft_parse_specifier(format, &format_info);
	return (format_info);
}
