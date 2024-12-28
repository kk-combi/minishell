/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:14:22 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 15:42:53 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n--)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void	check(int n, int d)
// {
// 	if (n == 0)
// 		printf("先頭から%dバイトは一致しています。\n", d);
// 	else
// 		printf("一致していません。: %d\n", n);
// }

// int	main(void)
// {
// 	char	buf[] = "ABCD5EFGH";
// 	char	buf2[] = "ABC123456";

// 	check(memcmp(buf, buf2, 3), 3);
// 	check(memcmp("ABCDGHIJK", "ABCDEFGHI", 5), 5);
// 	check(memcmp("ABCDEFGHI", "ABCDGHIJK", 5), 5);
// 	check(memcmp("ABCDEJGHI", "ABCDEFGHI", 6), 6);
// 	check(memcmp("ABGDEFG", "ABCDEFG", 2), 2);
// 	printf("-------↑ORIGINAL-------\n");
// 	check(ft_memcmp(buf, buf2, 3), 3);
// 	check(ft_memcmp("ABCDGHIJK", "ABCDEFGHI", 5), 5);
// 	check(ft_memcmp("ABCDEFGHI", "ABCDGHIJK", 5), 5);
// 	check(ft_memcmp("ABCDEJGHI", "ABCDEFGHI", 6), 6);
// 	check(ft_memcmp("ABGDEFG", "ABCDEFG", 2), 2);
// }
