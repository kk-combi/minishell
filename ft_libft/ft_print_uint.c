/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:29:28 by kasasaki          #+#    #+#             */
/*   Updated: 2024/11/24 12:36:22 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putn_fd(long long n, int fd)
{
	int		result;
	char	c;

	if (n == LLONG_MIN)
		return (write(fd, STR_LLONG_MIN, sizeof(STR_LLONG_MIN)));
	result = 0;
	if (n < 0)
	{
		result = write(fd, "-", 1);
		if (result < 0)
			return (-1);
		n = -n;
	}
	if (n >= 10)
		ft_putn_fd((n / 10), fd);
	c = n % 10 + '0';
	return (write(fd, &c, sizeof(c)));
}

int	ft_print_uint(unsigned int n)
{
	int	tmp;

	tmp = 0;
	tmp = ft_putn_fd(n, FD_STDOUT);
	if (tmp < 0)
		return (-1);
	return (ft_calc_digit(n));
}
