/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ptr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:11:10 by welee             #+#    #+#             */
/*   Updated: 2024/06/06 00:15:04 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
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

void	test_ptr_left_align(void)
{
	const char	*format = "Hello %-12p!\n";
	const char	*input = "world";
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

void	test_ptr_right_align(void)
{
	const char	*format = "Hello %12p!\n";
	const char	*input = "world";
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

void	test_ptr_zero_padded(void)
{
	const char	*format = "Hello %012p!\n";
	const char	*input = "world";
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

void	test_ptr_left_align_zero_padded(void)
{
	const char	*format = "Hello %-012p!\n";
	const char	*input = "world";
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

void	test_ptr_zero_padded_left_align(void)
{
	const char	*format = "Hello %0-12p!\n";
	const char	*input = "world";
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

void	test_ptr_zero_left_align_all_flags(void)
{
	const char	*format = "Hello %0-# +12p!\n";
	const char	*input = "world";
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

void	test_ptr_zero_padded_multiple_str(void)
{
	const char	*format = "Hello %0-# +10s! %0-# +10s! %0-# +10s!\n";
	const char	*input[] = {"world", "world", "world"};
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

void	test_ptr_plus_flag(void)
{
	const char	*format = "Hello %+p!\n";
	const char	*input = "world";
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

void	test_ptr_left_align_width(void)
{
	const char	*format = " %-1p %-2p \n";
	const int	input[] = {0, 0};
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input[0], input[1]);
	printf(format, input[0], input[1]);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input[0], input[1]);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input[0], input[1]);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_ptr_precision(void)
{
	const char	*format = " %16.1p %16.2p \n";
	const int	input[] = {0, 0};
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input[0], input[1]);
	printf(format, input[0], input[1]);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input[0], input[1]);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input[0], input[1]);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_ptr_long(void)
{
	const char	*format = " %p %p \n";
	const long	input[] = {LONG_MIN, LONG_MAX};
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input[0], input[1]);
	printf(format, input[0], input[1]);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input[0], input[1]);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input[0], input[1]);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_ptr_ulong(void)
{
	const char	*format = " %-13p %-14p \n";
	const long	input[] = {ULONG_MAX, -ULONG_MAX};
	char		buf_ft_printf[100];
	char		buf_printf[100];
	int			ft_printf_len;
	int			printf_len;

	ft_printf(format, input[0], input[1]);
	printf(format, input[0], input[1]);
	ft_printf_len = capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input[0], input[1]);
	printf_len = capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input[0], input[1]);
	printf("ft_printf_len: %d\n", ft_printf_len);
	printf("printf_len: %d\n", printf_len);
	assert(ft_printf_len == printf_len);
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_ptr(void)
{
	// run_test(test_ptr_left_align,
	// 	"test_ptr_left_align");
	// run_test(test_ptr_right_align,
	// 	"test_ptr_right_align");
	// run_test(test_ptr_zero_padded,
	// 	"test_ptr_zero_padded");
	// run_test(test_ptr_left_align_zero_padded,
	// 	"test_ptr_left_align_zero_padded");
	// run_test(test_ptr_zero_padded_left_align,
	// 	"test_ptr_zero_padded_left_align");
	// run_test(test_ptr_zero_left_align_all_flags,
	// 	"test_ptr_zero_left_align_all_flags");
	// // run_test(test_ptr_zero_padded_multiple_str,
	// // 	"test_ptr_zero_padded_multiple_str");
	// run_test(test_ptr_plus_flag,
	// 	"test_ptr_plus_flag");
	// run_test(test_ptr_left_align_width,
	// 	"test_ptr_left_align_width");
	// run_test(test_ptr_precision,
	// 	"test_ptr_precision");
	// run_test(test_ptr_long, "test_ptr_long");
	run_test(test_ptr_ulong, "test_ptr_ulong");
}

int	main(void)
{
	test_ptr();
	printf("All tests passed!\n");
	return (0);
}
