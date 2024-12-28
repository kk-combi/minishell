/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:08:39 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 20:34:08 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	j = 0;
	while (j < size - 1 && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	src1[] = "HelloWorld";
// 	char	dest[30];
// 	int		i1;
// 	int		i2;

// 	i1 = ft_strlcpy(dest, src1, sizeof(src1));
// 	printf("%s: %d\n", src1, i1);
// 	i2 = ft_strlcpy(dest, src1, 0);
// 	printf("%s: %d\n", src1, i2);
// 	return (0);
// }
