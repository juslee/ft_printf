/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:34:42 by welee             #+#    #+#             */
/*   Updated: 2024/06/12 11:37:05 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf_bonus.h"

int	test_ft_printf_bonus(const char *format, ...)
{
	va_list	args1, args2;
	int		ft_ret, std_ret;
	char	ft_buf[1024], std_buf[1024];

	va_start(args1, format);
	va_copy(args2, args1);

	// Redirect output of ft_printf to ft_buf
	FILE *ft_fp = fmemopen(ft_buf, sizeof(ft_buf), "w");
	if (!ft_fp)
		return (-1);
	dup2(fileno(ft_fp), fileno(stdout));
	ft_ret = ft_vprintf(format, args1);
	fclose(ft_fp);

	// Redirect output of printf to std_buf
	FILE *std_fp = fmemopen(std_buf, sizeof(std_buf), "w");
	if (!std_fp)
		return (-1);
	dup2(fileno(std_fp), fileno(stdout));
	std_ret = vprintf(format, args2);
	fclose(std_fp);

	va_end(args1);
	va_end(args2);

	// Compare outputs and return values
	if (strcmp(ft_buf, std_buf) != 0 || ft_ret != std_ret)
	{
		printf("Test failed:\n");
		printf("Format: %s\n", format);
		printf("Expected: %s (ret=%d)\n", std_buf, std_ret);
		printf("Got: %s (ret=%d)\n", ft_buf, ft_ret);
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	result = 0;

	result += test_ft_printf_bonus("Bonus test with flags: %+d, %#x, %0*d\n", 42, 42, 5, 42);
	result += test_ft_printf_bonus("Another test: % .2f, %-10s\n", 3.1415, "test");

	if (result == 0)
		printf("All bonus tests passed!\n");
	else
		printf("Some bonus tests failed.\n");

	return (result != 0);
}
