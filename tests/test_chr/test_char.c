/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:21:59 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 19:15:54 by welee            ###   ########.fr       */
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

void	test_basic_char(void)
{
	const char	*format = "Hello %c";
	const char	input = 'X';
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_null_char(void)
{
	const char	*format = "Null char: %c";
	const char	input = 'X';
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_char_at_beginning(void)
{
	const char	*format = "%c is the first character";
	const char	input = 'X';
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_char_at_end(void)
{
	const char	*format = "End with %c";
	const char	input = 'Z';
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_multiple_chars(void)
{
	const char	*format = "%c%c%c";
	const char	input[3] = {'a', 'b', 'c'};
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format,
			input[0], input[1], input[2])
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format,
			input[0], input[1], input[2]));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_char(void)
{
	run_test(test_basic_char, "test_basic_char");
	run_test(test_null_char, "test_null_char");
	run_test(test_char_at_beginning, "test_char_at_beginning");
	run_test(test_char_at_end, "test_char_at_end");
	run_test(test_multiple_chars, "test_multiple_chars");
}

int	main(void)
{
	test_char();
	printf("All tests passed!\n");
	return (0);
}
