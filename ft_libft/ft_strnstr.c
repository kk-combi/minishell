/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:54:23 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 19:16:45 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	n = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[n])
		{
			while (big[i + n] == little[n] && (i + n) < len)
			{
				if (little[n + 1] == '\0')
					return ((char *)(big + i));
				n++;
			}
			n = 0;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// void	check(char *result)
// {
// 	if (result == NULL)
// 		printf("%s\n", "no match!");
// 	else
// 		printf("%s\n", result);
// }

// int	main(void)
// {
// 	char	*largestring;
// 	char	*smallstring;
// 	char	haystack[30] = "aaabcabcd";

// 	largestring = "Foo Bar Baz";
// 	smallstring = "Bar";
// 	check(ft_strnstr(largestring, "Bar", ft_strlen(largestring)));
// 	check(ft_strnstr(largestring, "Bar", 3));
// 	check(ft_strnstr(smallstring, "Bar", 3));
// 	check(ft_strnstr(largestring, "Bar", 2));
// 	check(ft_strnstr(smallstring, "Bar", 2));
// 	check(ft_strnstr(haystack, "cd", 8));
// 	return (0);
// }
