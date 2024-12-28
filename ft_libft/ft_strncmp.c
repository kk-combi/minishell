/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:50:00 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/24 20:57:22 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	test1[10] = "abc12";
// 	char	test2[10] = "abcde";

// 	// test1とtest2の文字列を先頭から5文字比較
// 	if (ft_strncmp(test1, test2, 5) == 0)
// 		puts("文字列は一致しています。");
// 	else
// 		puts("文字列は一致していません。");
// 	// test1とtest2の文字列を先頭から３文字比較
// 	if (ft_strncmp(test1, test2, 3) == 0)
// 		puts("文字列は一致しています。");
// 	else
// 		puts("文字列は一致していません。");
// }
