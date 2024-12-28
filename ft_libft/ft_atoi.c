/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:45:59 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 20:05:13 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*remove_sp(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v')
			str++;
		else
			break ;
	}
	return (str);
}

int	ft_atoi(const char *nptr)
{
	int		num;
	int		sign;
	char	*result;

	num = 0;
	sign = 1;
	result = remove_sp((char *)nptr);
	if (*result == '-' || *result == '+')
	{
		if (*result == '-')
			sign = -1;
		result++;
	}
	while (*result)
	{
		if (!(*result >= '0' && *result <= '9'))
			break ;
		num = num * 10 + (*result - '0');
		result++;
	}
	return (num * sign);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int	main(void)
// {
// 	printf("%d\n", atoi("	\n\f\r\t\v2147483647ab"));
// 	printf("%d\n", atoi(" 0ab"));
// 	printf("%d\n", atoi("    -2147483648aaa"));
// 	printf("%d\n", atoi("    +214aaa"));
// 	printf("%d\n", atoi("    ---214aaa"));
// 	printf("%d\n", atoi("    ++214aaa"));
// 	printf("%d\n", atoi("2147483648"));
// 	printf("%d\n", atoi("    -2147483649"));
// 	printf("%d\n", atoi("abcd214aaa"));
// 	printf("---------↑original---------\n");
// 	printf("%d\n", ft_atoi("	\n\f\r\t\v2147483647ab"));
// 	printf("%d\n", ft_atoi(" 0ab"));
// 	printf("%d\n", ft_atoi("    -2147483648aaa"));
// 	printf("%d\n", ft_atoi("    +214aaa"));
// 	printf("%d\n", ft_atoi("    ---214aaa"));
// 	printf("%d\n", ft_atoi("    ++214aaa"));
// 	printf("%d\n", ft_atoi("2147483648"));
// 	printf("%d\n", ft_atoi("    -2147483649"));
// 	printf("%d\n", ft_atoi("abcd214aaa"));
// 	return (0);
// }
