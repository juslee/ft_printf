/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:21:59 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 20:51:22 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
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

void	test_str_left_align(void)
{
	const char	*format = "Hello %-10s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_str_right_align(void)
{
	const char	*format = "Hello %10s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_str_zero_padded(void)
{
	const char	*format = "Hello %010s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_str_left_align_zero_padded(void)
{
	const char	*format = "Hello %-010s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_str_zero_padded_left_align(void)
{
	const char	*format = "Hello %0-10s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_str_zero_padded_left_align_all_flags(void)
{
	const char	*format = "Hello %0-# +10s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_str_zero_padded_multiple_str(void)
{
	const char	*format = "Hello %0-# +10s! %0-# +10s! %0-# +10s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
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

void	test_str_precision_lower(void)
{
	const char	*format = "Strings: %.2s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
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

void	test_str_precision_upper(void)
{
	const char	*format = "Strings: %.6s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
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

void	test_str_width_precision(void)
{
	const char	*format = "Strings: %5.2s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
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

void	test_str_width_precision_larger(void)
{
	const char	*format = "Strings: %2.5s!\n";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input);
	printf(format, input);
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

void	test_str(void)
{
	run_test(test_str_left_align,
		"test_str_left_align");
	run_test(test_str_right_align,
		"test_str_right_align");
	run_test(test_str_zero_padded,
		"test_str_zero_padded");
	run_test(test_str_left_align_zero_padded,
		"test_str_left_align_zero_padded");
	run_test(test_str_zero_padded_left_align,
		"test_str_zero_padded_left_align");
	run_test(test_str_zero_padded_left_align_all_flags,
		"test_str_zero_padded_left_align_all_flags");
	run_test(test_str_zero_padded_multiple_str,
		"test_str_zero_padded_multiple_str");
	run_test(test_str_precision_lower,
		"test_str_precision_lower");
	run_test(test_str_precision_upper,
		"test_str_precision_upper");
	run_test(test_str_width_precision,
		"test_str_width_precision");
	run_test(test_str_width_precision_larger,
		"test_str_width_precision_larger");
}

int	main(void)
{
	test_str();
	printf("All tests passed!\n");
	return (0);
}
