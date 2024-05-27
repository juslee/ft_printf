/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:54:23 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 19:09:46 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "ft_printf.h"
#include "ft_printf_util.h"

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
	const char	*format = "Number: %d\n";
	const int	input = 42;
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_integer(void)
{
	const char	*format = "Integer: %i\n";
	const int	input = -42;
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_large_number(void)
{
	const char	*format = "Large: %d\n";
	const int	input = INT_MAX;
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_negative_large_number(void)
{
	const char	*format = "Negative Large: %d\n";
	const int	input = INT_MIN;
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void test_numbers(void)
{
	run_test(test_decimal, "test_decimal");
	run_test(test_integer, "test_integer");
	run_test(test_large_number, "test_large_number");
	run_test(test_negative_large_number, "test_negative_large_number");
}

int	main(void)
{
	test_numbers();
	printf("All tests passed!\n");
	return (0);
}
