/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:32:56 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 15:42:02 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_isprint(0));
// 	printf("%d\n", ft_isprint('0'));
// 	printf("%d\n", ft_isprint('~'));
// 	printf("%d\n", ft_isprint('A'));
// 	printf("%d\n", ft_isprint(' '));
// 	printf("%d\n", ft_isprint(128));
// 	printf("%d\n", ft_isprint(-1));
// }
