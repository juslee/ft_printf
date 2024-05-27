/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:19:14 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 19:10:00 by welee            ###   ########.fr       */
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

void	test_single_percent(void)
{
	const char 	*format = "Percent: %%";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0, buf_ft_printf, sizeof(buf_ft_printf) - 1, format)
		== capture_output(1, buf_printf, sizeof(buf_printf) - 1, format));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_multiple_percents(void)
{
	const char	*format = "%% %% %%";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0, buf_ft_printf, sizeof(buf_ft_printf) - 1, format)
		== capture_output(1, buf_printf, sizeof(buf_printf) - 1, format));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_percent_with_text(void)
{
	const char	*format = "100%% sure!";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0, buf_ft_printf, sizeof(buf_ft_printf) - 1, format)
		== capture_output(1, buf_printf, sizeof(buf_printf) - 1, format));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_percent_in_sentence(void)
{
	const char	*format = "This is 50%% accurate.";
	char		buf_ft_printf[100];
	char		buf_printf[100];

	assert(capture_output(0, buf_ft_printf, sizeof(buf_ft_printf) - 1, format)
		== capture_output(1, buf_printf, sizeof(buf_printf) - 1, format));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_percent(void)
{
	run_test(test_single_percent, "test_single_percent");
	run_test(test_multiple_percents, "test_multiple_percents");
	run_test(test_percent_with_text, "test_percent_with_text");
	run_test(test_percent_in_sentence, "test_percent_in_sentence");
}

int	main(void)
{
	test_percent();
	printf("All percent tests passed!\n");
	return (0);
}
