/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:23:13 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 21:12:04 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd((n / 10), fd);
	c = n % 10 + '0';
	write(fd, &c, sizeof(c));
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_putnbr_fd(INT_MIN, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-2344, 1);
// 	printf("\n");
// 	ft_putnbr_fd(0, 1);
// 	printf("\n");
// 	ft_putnbr_fd(10, 1);
// 	printf("\n");
// 	ft_putnbr_fd(1245, 1);
// 	printf("\n");
// 	ft_putnbr_fd(INT_MAX, 1);
// 	printf("\n");
// }
