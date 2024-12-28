/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:09:48 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 11:51:35 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcat(result + (s1_len), s2, s2_len + 1);
	return (result);
}

// #include <stdio.h>
// #include <unistd.h>

// void	check(char *result)
// {
// 	if (result)
// 		printf("%s\n", result);
// 	else
// 		printf("%s\n", "result is null");
// 	free(result);
// }

// int	main(void)
// {
// 	check(ft_strjoin("Hello", "World!"));
// 	check(ft_strjoin("Hello", NULL));
// 	check(ft_strjoin(NULL, "World!"));
// 	check(ft_strjoin("", ""));
// 	check(ft_strjoin(NULL, NULL));
// }
