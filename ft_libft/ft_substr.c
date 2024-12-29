/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:45:49 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/26 10:09:01 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (len <= 0 || s_len < start)
		return (ft_calloc(1, 1));
	if (s_len - start < len)
		len = s_len - start;
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

// #include <stdio.h>

// void	check(char *result)
// {
// 	if (result)
// 		printf("result!: %s\n", result);
// 	else
// 		printf("result is null!\n");
// }

// int	main(void)
// {
// 	check(ft_substr("HelloWorld!", 5, 3));
// }
