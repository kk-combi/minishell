/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:37:25 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 11:10:44 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// REF
// https://scrapbox.io/42tokyo-42cursus/ft_strtrim
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	p = ft_substr(s1, 0, s1_len);
	if (p)
		return (p);
	return (NULL);
}

// #include <stdio.h>

// void	check(char *result)
// {
// 	if (result)
// 	{
// 		printf("Trimmed string: '%s'\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("The result is Null\n");
// }

// int	main(void)
// {
// 	char	*s1;
// 	char	*set;

// 	s1 = "  Hello, World!  ";
// 	set = " ";
// 	check(ft_strtrim(s1, set));
// 	return (0);
// }
