/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nbr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:29:31 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 17:00:34 by welee            ###   ########.fr       */
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

void	test_decimal_left_align(void)
{
	const char	*format = "Hello %-12d world\n";
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

void	test_decimal_right_align(void)
{
	const char	*format = "Hello %12d world\n";
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

void	test_decimal_zero_padded(void)
{
	const char	*format = "Hello %012d world\n";
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

void	test_decimal_left_align_zero_padded(void)
{
	const char	*format = "Hello %-012d world\n";
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

void	test_decimal_zero_padded_left_align(void)
{
	const char	*format = "Hello %0-12d world\n";
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

void	test_decimal_zero_padded_left_align_all_flags(void)
{
	const char	*format = "Hello %0-# +12d world\n";
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

void	test_decimal_zero_padded_multiple_decimal(void)
{
	const char	*format = "Hello %0-# +12d! %0-# +12d! %0-# +12d!\n";
	const int	input = 42;
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input, input, input);
	printf(format, input, input, input);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format,
			input, input, input);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format,
			input, input, input);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_numbers_left_align_width(void)
{
	const char	*format = " %-4d !\n";
	const int	input = -14;
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

void	test_numbers_zero_padded_width(void)
{
	const char	*format = " %04d !\n";
	const int	input = -14;
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

void	test_numbers(void)
{
	run_test(test_decimal_left_align, "test_decimal_left_align");
	run_test(test_decimal_right_align, "test_decimal_right_align");
	run_test(test_decimal_zero_padded, "test_decimal_zero_padded");
	run_test(test_decimal_left_align_zero_padded,
		"test_decimal_left_align_zero_padded");
	run_test(test_decimal_zero_padded_left_align,
		"test_decimal_zero_padded_left_align");
	run_test(test_decimal_zero_padded_left_align_all_flags,
		"test_decimal_zero_padded_left_align_all_flags");
	run_test(test_decimal_zero_padded_multiple_decimal,
		"test_decimal_zero_padded_multiple_decimal");
	// run_test(test_numbers_left_align_width,
	// 	"test_numbers_left_align_width");
	run_test(test_numbers_zero_padded_width,
		"test_numbers_zero_padded_width");
}

int	main(void)
{
	test_numbers();
	return (0);
}
