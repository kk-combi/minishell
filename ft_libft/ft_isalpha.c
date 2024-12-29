/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:25:07 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 14:56:30 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	c;
// 	char	c2;

// 	c = 'a';
// 	printf("%s\n", "-------check is upper or lower-----");
// 	printf("%d\n", ft_isupper(c));
// 	printf("%d\n", ft_islower(c));
// 	c2 = 'A';
// 	printf("%d\n", ft_isupper(c2));
// 	printf("%d\n", ft_islower(c2));
// 	printf("%s\n", "-------check is upper or lower-----");
// 	printf("%s\n", "-------check is alpha-----");
// 	printf("%d\n", ft_isalpha(c));
// 	printf("%d\n", ft_isalpha(c2));
// 	printf("%d\n", ft_isalpha('@'));
// 	printf("%d\n", ft_isalpha('`'));
// 	printf("%s\n", "-------check is alpha-----");
// }
