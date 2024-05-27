/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:18:44 by welee             #+#    #+#             */
/*   Updated: 2024/05/27 19:09:38 by welee            ###   ########.fr       */
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

void	test_hex_lowercase_alternate_form(void)
{
	const char			*format = "Hex: %#x\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_alternate_form(void)
{
	const char			*format = "Hex: %#X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_zero_padding(void)
{
	const char			*format = "Hex: %020x\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_zero_padding(void)
{
	const char			*format = "Hex: %020X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_zero_padding_alternate_form(void)
{
	const char			*format = "Hex: %#020x\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_zero_padding_alternate_form(void)
{
	const char			*format = "Hex: %#020X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_space(void)
{
	const char			*format = "Hex: % x\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_space(void)
{
	const char			*format = "Hex: % X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_plus(void)
{
	const char			*format = "Hex: %+x\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_plus(void)
{
	const char			*format = "Hex: %+X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_plus_space(void)
{
	const char			*format = "Hex: %+ x\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_plus_space(void)
{
	const char			*format = "Hex: %+ X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_plus_space_zero_padding(void)
{
	const char			*format = "Hex: %0 +20x\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_plus_space_zero_padding(void)
{
	const char			*format = "Hex: %0 +20X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_plus_space_zero_padding_alternate_form(void)
{
	const char			*format = "Hex: %#0 +20X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_plus_space_zero_padding_alternate_form(void)
{
	const char			*format = "Hex: %#0 +20X\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_plus_space_zero_padding_left_align(void)
{
	const char			*format = "Hex: %-0 +20x!\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_plus_space_zero_padding_left_align(void)
{
	const char			*format = "Hex: %-0 +20X!\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_lowercase_plus_space_zero_padding_left_align_alternate_form(void)
{
	const char			*format = "Hex: %-#0 +20x!\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex_uppercase_plus_space_zero_padding_left_align_alternate_form(void)
{
	const char			*format = "Hex: %-#0 +20X!\n";
	const unsigned int	input = 255;
	char				buf_ft_printf[100];
	char				buf_printf[100];

	ft_printf(format, input);
	printf(format, input);
	assert(capture_output(0,
			buf_ft_printf, sizeof(buf_ft_printf) - 1, format, input)
		== capture_output(1,
			buf_printf, sizeof(buf_printf) - 1, format, input));
	assert(strcmp(buf_ft_printf, buf_printf) == 0);
}

void	test_hex(void)
{
	run_test(test_hex_lowercase_alternate_form, "test_hex_lowercase_alternate_form");
	run_test(test_hex_uppercase_alternate_form, "test_hex_uppercase_alternate_form");
	run_test(test_hex_lowercase_zero_padding, "test_hex_lowercase_zero_padding");
	run_test(test_hex_uppercase_zero_padding, "test_hex_uppercase_zero_padding");
	run_test(test_hex_lowercase_zero_padding_alternate_form, "test_hex_lowercase_zero_padding_alternate_form");
	run_test(test_hex_uppercase_zero_padding_alternate_form, "test_hex_uppercase_zero_padding_alternate_form");
	run_test(test_hex_lowercase_space, "test_hex_lowercase_space");
	run_test(test_hex_uppercase_space, "test_hex_uppercase_space");
	run_test(test_hex_lowercase_plus, "test_hex_lowercase_plus");
	run_test(test_hex_uppercase_plus, "test_hex_uppercase_plus");
	run_test(test_hex_lowercase_plus_space, "test_hex_lowercase_plus_space");
	run_test(test_hex_uppercase_plus_space, "test_hex_uppercase_plus_space");
	run_test(test_hex_lowercase_plus_space_zero_padding, "test_hex_lowercase_plus_space_zero_padding");
	run_test(test_hex_uppercase_plus_space_zero_padding, "test_hex_uppercase_plus_space_zero_padding");
	run_test(test_hex_lowercase_plus_space_zero_padding_alternate_form, "test_hex_lowercase_plus_space_zero_padding_alternate_form");
	run_test(test_hex_uppercase_plus_space_zero_padding_alternate_form, "test_hex_uppercase_plus_space_zero_padding_alternate_form");
	run_test(test_hex_lowercase_plus_space_zero_padding_left_align, "test_hex_lowercase_plus_space_zero_padding_left_align");
	run_test(test_hex_uppercase_plus_space_zero_padding_left_align, "test_hex_uppercase_plus_space_zero_padding_left_align");
	run_test(test_hex_lowercase_plus_space_zero_padding_left_align_alternate_form, "test_hex_lowercase_plus_space_zero_padding_left_align_alternate_form");
	run_test(test_hex_uppercase_plus_space_zero_padding_left_align_alternate_form, "test_hex_uppercase_plus_space_zero_padding_left_align_alternate_form");
}

int	main(void)
{
	test_hex();
	printf("All tests passed!\n");
	return (0);
}
