/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:34:01 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 20:33:34 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + src_len);
	while (src[i] && i < (size - dst_len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		cnt;
// 	int		n;
// 	char	dest[30] = "ABCDE";
// 	char	src[] = "1234";

// 	n = 13;
// 	cnt = ft_strlcat(dest, src, n);
// 	printf("%s:cnt: %d\n", dest, cnt);
// 	return (0);
// }
