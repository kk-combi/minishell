/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:28 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 18:45:52 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + len));
	while (len > 0)
	{
		if (s[len - 1] == (char)c)
			return ((char *)(s + len - 1));
		len--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("%s\n", ft_strrchr("abcdefghijk", 'f'));
// 	printf("%s\n", ft_strrchr("abcdefghijk", 0));
// 	printf("%s\n", ft_strrchr("abcdefgabhijk", 'a'));
// 	printf("%s\n", ft_strrchr("abcdefghijk", 'w'));
// 	printf("----↓original------\n");
// 	printf("%s\n", strrchr("abcdefghijk", 'f'));
// 	printf("%s\n", strrchr("abcdefghijk", 0));
// 	printf("%s\n", strrchr("abcdefgabhijk", 'a'));
// 	printf("%s\n", strrchr("abcdefghijk", 'w'));
// }
