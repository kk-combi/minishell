/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:58:16 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 17:24:53 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void	check(char *ch)
// {
// 	if (ch != NULL)
// 	{
// 		printf("検索文字から表示 → %s\n", ch);
// 	}
// 	else
// 	{
// 		puts("検索文字が見つかりませんでした。");
// 	}
// }

// int	main(void)
// {
// 	char	buf[] = "ABCD5EFGH";

// 	check((char *)ft_memchr(buf, '5', sizeof(buf)));
// 	check((char *)ft_memchr(buf, '9', sizeof(buf)));
// 	printf("-------↓original-----\n");
// 	check((char *)memchr(buf, '5', sizeof(buf)));
// 	check((char *)memchr(buf, '9', sizeof(buf)));
// 	return (0);
// }
