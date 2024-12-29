/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:48:42 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/24 19:45:46 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	buf[] = "ABCDEFGHIJK";

// 	printf("bf buf文字列→%s\n", buf);
// 	//先頭から2バイト進めた位置に「１」を3バイト書き込む
// 	ft_memset(buf + 2, '1', 3);
// 	printf("after buf文字列→%s\n", buf);
// }
