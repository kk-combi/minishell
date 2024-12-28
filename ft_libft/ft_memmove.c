/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:14:36 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 20:46:15 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (d == s)
		return (dest);
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
		return (dest);
	}
	d += n;
	s += n;
	while (n--)
		*--d = *--s;
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	buf[] = "ABCDDEFG";

// 	printf("コピー前のbuf文字列→%s\n", buf);
// 	// bufの先頭から3バイト進めた位置にbufの先頭から3バイトコピー
// 	ft_memmove(buf + 3, buf, 3);
// 	printf("コピー後のbuf文字列→%s\n", buf);
// }
