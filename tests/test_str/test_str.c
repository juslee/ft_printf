/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:42:00 by welee             #+#    #+#             */
/*   Updated: 2024/05/24 14:11:21 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
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

void	test_basic_str(void)
{
	const char	*format = "Hello %s";
	const char	*input = "world";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_empty_str(void)
{
	const char	*format = "Hello %s";
	const char	*input = "";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_null_string(void)
{
	const char	*format = "Null string: %s";
	const char	*input = NULL;
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_long_string(void)
{
	const char	*format = "Long: %s";
	const char	*input = "This is a very long string that is used to test the"
		"handling of long inputs in the ft_printf function. It should be able"
		"to process this without any issues.";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_special_string(void)
{
	const char	*format = "Special: %s";
	const char	*input = "!@#$%^&*()_+-=~`";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_str(void)
{
	run_test(test_basic_str, "test_basic_str");
	run_test(test_empty_str, "test_empty_str");
	run_test(test_null_string, "test_null_string");
	run_test(test_long_string, "test_long_string");
	run_test(test_special_string, "test_special_string");
}

int	main(void)
{
	test_str();
	printf("All tests passed!\n");
	return (0);
}
