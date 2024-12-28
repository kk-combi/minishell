/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:44:21 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 14:50:52 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_digit_len(long long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*set_num_for_minus(long long n)
{
	char	*result;
	int		i;
	int		digit_len;

	digit_len = calc_digit_len(n);
	result = malloc(sizeof(char) * ((digit_len + 1) + 1));
	if (!result)
		return (NULL);
	result[0] = '-';
	i = 0;
	while (n > 0)
	{
		result[digit_len - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	result[digit_len + 1] = '\0';
	return (result);
}

static char	*set_num(long long n)
{
	char	*result;
	int		i;
	int		digit_len;

	digit_len = calc_digit_len(n);
	result = malloc(sizeof(char) * (digit_len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		result[digit_len - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;

	if (n < 0)
		return (set_num_for_minus(-(long long)n));
	if (n == 0)
	{
		result = malloc(sizeof(char) * 2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	return (set_num((long long)n));
}

// #include <stdio.h>

// void	check(char *result)
// {
// 	if (result)
// 		printf("%s\n", result);
// 	else
// 		printf("result is NULL\n");
// }

// int	main(void)
// {
// 	check(ft_itoa(INT32_MAX));
// 	check(ft_itoa(21474));
// 	check(ft_itoa(0));
// 	check(ft_itoa(-2147));
// 	check(ft_itoa(INT32_MIN));
// }
