/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:21:59 by welee             #+#    #+#             */
/*   Updated: 2024/05/20 20:43:01 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	capture_output(char *buf, size_t size, const char *format, ...)
{
	int		saved_stdout;
	FILE	*temp;
	int		temp_fd;
	int		len;
	va_list	args;

	fflush(stdout);
	saved_stdout = dup(1);
	temp = tmpfile();
	temp_fd = fileno(temp);
	dup2(temp_fd, 1);
	va_start(args, format);
	ft_printf(format, va_arg(args, int));
	va_end(args);
	fflush(stdout);
	fseek(temp, 0, SEEK_SET);
	len = read(temp_fd, buf, size - 1);
	buf[len] = '\0';
	dup2(saved_stdout, 1);
	close(saved_stdout);
	fclose(temp);
	return (len);
}

void	test_basic_character_output(void)
{
	char	buffer[100];
	int		len;

	len = capture_output(buffer, sizeof(buffer), "%c", 'A');
	assert(strcmp(buffer, "A") == 0);
	assert(len == 1);
	printf("test_basic_character_output passed.\n");
}

void	test_non_printable_characters(void)
{
	char	buffer[100];
	int		len;

	len = capture_output(buffer, sizeof(buffer), "%c", '\n');
	assert(strcmp(buffer, "\n") == 0);
	assert(len == 1);

	len = capture_output(buffer, sizeof(buffer), "%c", '\t');
	assert(strcmp(buffer, "\t") == 0);
	assert(len == 1);
	printf("test_non_printable_characters passed.\n");
}

void	test_multiple_character_arguments(void)
{
	char	buffer[100];
	int		len;

	len = capture_output(buffer, sizeof(buffer), "%c %c %c", 'A', 'B', 'C');
	assert(strcmp(buffer, "A B C") == 0);
	assert(len == 5);
	printf("test_multiple_character_arguments passed.\n");
}

void	test_format_string_with_mixed_characters(void)
{
	char	buffer[100];
	int		len;

	len = capture_output(buffer, sizeof(buffer), "Char: %c, Another: %c", 'X', 'Y');
	assert(strcmp(buffer, "Char: X, Another: Y") == 0);
	assert(len == 19);
	printf("test_format_string_with_mixed_characters passed.\n");
}

void	test_null_character(void)
{
	char	buffer[100];
	int		len;

	len = capture_output(buffer, sizeof(buffer), "%c", '\0');
	assert(buffer[0] == '\0');
	assert(len == 1);
	printf("test_null_character passed.\n");
}

int	main(void)
{
	test_basic_character_output();
	test_non_printable_characters();
	test_multiple_character_arguments();
	test_format_string_with_mixed_characters();
	test_null_character();

	printf("All tests passed.\n");
	return (0);
}
