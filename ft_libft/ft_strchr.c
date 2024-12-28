/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:28:44 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 18:45:23 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("%s\n", ft_strchr("abcdefghijk", 'f'));
// 	printf("%s\n", ft_strchr("abcdefghijk", 'w'));
// 	printf("%s\n", ft_strchr("abcdefghijk", 0));
// 	printf("----↓original------\n");
// 	printf("%s\n", strchr("abcdefghijk", 'f'));
// 	printf("%s\n", strchr("abcdefghijk", 'w'));
// 	printf("%s\n", strchr("abcdefghijk", 0));
// }
