/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:12:11 by kasasaki          #+#    #+#             */
/*   Updated: 2024/11/24 12:40:36 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc_digit(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len = 1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	putnbr_fd(long long n, int fd)
{
	int		result;
	char	c;

	result = 0;
	if (n < 0)
	{
		result = write(fd, "-", 1);
		if (result < 0)
			return (-1);
		n = -n;
	}
	if (n >= 10)
		putnbr_fd((n / 10), fd);
	c = n % 10 + '0';
	return (write(fd, &c, sizeof(c)));
}

int	ft_print_int(int n)
{
	int	tmp;

	tmp = 0;
	tmp = putnbr_fd(n, FD_STDOUT);
	if (tmp < 0)
		return (-1);
	return (ft_calc_digit(n));
}
