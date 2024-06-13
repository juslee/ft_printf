/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 08:51:29 by welee             #+#    #+#             */
/*   Updated: 2024/06/13 09:18:35 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_ft_printf.h"

int	test_ft_printf(const char *format, ...)
{
	va_list	args1, args2;
	int		ft_ret, std_ret;
	char	ft_buf[1024], std_buf[1024];
	FILE	*ft_fp;
	FILE	*std_fp;

	va_start(args1, format);
	va_copy(args2, args1);
	ft_fp = fmemopen(ft_buf, sizeof(ft_buf), "w");
	if (!ft_fp)
		return (-1);
	dup2(fileno(ft_fp), fileno(stdout));
	ft_ret = ft_vprintf(format, args1);
	fclose(ft_fp);
	std_fp = fmemopen(std_buf, sizeof(std_buf), "w");
	if (!std_fp)
		return (-1);
	dup2(fileno(std_fp), fileno(stdout));
	std_ret = vprintf(format, args2);
	fclose(std_fp);
	va_end(args1);
	va_end(args2);
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

	result += test_ft_printf("Hello, %s!\n", "world");
	result += test_ft_printf("Character: %c\n", 'A');
	result += test_ft_printf("Pointer: %p\n", (void *)0x12345678);
	result += test_ft_printf("Decimal: %d\n", 123);
	result += test_ft_printf("Integer: %i\n", -456);
	result += test_ft_printf("Unsigned: %u\n", 789);
	result += test_ft_printf("Hex (lower): %x\n", 0xabcdef);
	result += test_ft_printf("Hex (upper): %X\n", 0xABCDEF);
	result += test_ft_printf("Percent: %%\n");
	result += test_ft_printf("Pointer (LONG): %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	result += test_ft_printf("Pointer (INT): %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
	result += test_ft_printf("Pointer (ULONG): %p %p \n", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
	result += test_ft_printf("Character: %c%c%c\n", 'a', '\t', 'b');
	result += test_ft_printf("Integer (INT_MIN): %d\n", INT_MIN);
	result += test_ft_printf("No format: \001\002\007\v\010\f\r\n");
	result += test_ft_printf("Pointer (NULL): %p\n", NULL);

	if (result == 0)
		printf("All tests passed!\n");
	else
		printf("Some tests failed.\n");

	return (result != 0);
}
