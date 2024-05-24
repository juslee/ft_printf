/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:54:23 by welee             #+#    #+#             */
/*   Updated: 2024/05/24 15:13:48 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "ft_printf.h"

int	capture_output(int printf, char *buf, size_t size, const char *format, ...)
{
	int		saved_stdout;
	FILE	*temp;
	int		temp_fd;
	int		len;
	va_list	args;
	int		ret;

	fflush(stdout);
	saved_stdout = dup(1);
	temp = tmpfile();
	temp_fd = fileno(temp);
	dup2(temp_fd, 1);
	va_start(args, format);
	if (printf == 1)
		ret = vprintf(format, args);
	else
		ret = ft_vprintf(format, args);
	va_end(args);
	fflush(stdout);
	fseek(temp, 0, SEEK_SET);
	len = read(temp_fd, buf, size - 1);
	buf[len] = '\0';
	dup2(saved_stdout, 1);
	close(saved_stdout);
	fclose(temp);
	return (ret);
}

void	run_test(void (*test_func)(void), const char *test_name)
{
	printf("Running %s...\n", test_name);
	test_func();
	printf("%s passed!\n", test_name);
}

void	test_decimal(void)
{
	const char	*format = "Number: %d";
	const int	input = 42;
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_integer(void)
{
	const char	*format = "Integer: %i";
	const int	input = -42;
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_unsigned(void)
{
	const char		*format = "Unsigned: %u";
	unsigned int	input = 42;
	char			buf_ft_printf[100];
	char			buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase(void)
{
	const char			*format = "Hex: %x";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase(void)
{
	const char			*format = "Hex: %X";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_large_number(void)
{
	const char	*format = "Large: %d";
	const int	input = INT_MAX;
	char		buf_ft_printf[100];
	char	buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_negative_large_number(void)
{
	const char	*format = "Negative Large: %d";
	const int	input = INT_MIN;
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void test_numbers(void)
{
	run_test(test_decimal, "test_decimal");
	run_test(test_integer, "test_integer");
	run_test(test_unsigned, "test_unsigned");
	run_test(test_hex_lowercase, "test_hex_lowercase");
	run_test(test_hex_uppercase, "test_hex_uppercase");
	run_test(test_large_number, "test_large_number");
	run_test(test_negative_large_number, "test_negative_large_number");
}

int	main(void)
{
	test_numbers();
	return (0);
}
