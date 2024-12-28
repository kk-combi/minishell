/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:12:35 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/24 20:25:47 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	n;

	n = c;
	if (c >= 'a' && c <= 'z')
		n = c + ('A' - 'a');
	return (n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("ft_toupper: %c\n", ft_toupper('a'));
// 	printf("ft_toupper: %c\n", ft_toupper(98));
// 	printf("ft_toupper: %c\n", ft_toupper('A'));
// 	printf("ft_toupper: %c\n", ft_toupper('@'));
// 	printf("ft_toupper: %c\n", ft_toupper(0));
// 	printf("ft_toupper: %c\n", ft_toupper(-1));
// 	printf("ft_toupper: %c\n", ft_toupper(128));
// }
