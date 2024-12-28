/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:24:58 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/22 20:32:01 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_isascii(0));
// 	printf("%d\n", ft_isascii('0'));
// 	printf("%d\n", ft_isascii('9'));
// 	printf("%d\n", ft_isascii('A'));
// 	printf("%d\n", ft_isascii('-'));
// 	printf("%d\n", ft_isascii(128));
// 	printf("%d\n", ft_isascii(-1));
// }
