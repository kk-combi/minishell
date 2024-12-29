/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:23:44 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/24 20:26:54 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int	n;

	n = c;
	if (c >= 'A' && c <= 'Z')
		n = c + ('a' - 'A');
	return (n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("ft_tolower: %c\n", ft_tolower('a'));
// 	printf("ft_tolower: %c\n", ft_tolower(98));
// 	printf("ft_tolower: %c\n", ft_tolower('A'));
// 	printf("ft_tolower: %c\n", ft_tolower('@'));
// 	printf("ft_tolower: %c\n", ft_tolower(0));
// 	printf("ft_tolower: %c\n", ft_tolower(-1));
// 	printf("ft_tolower: %c\n", ft_tolower(128));
// }
