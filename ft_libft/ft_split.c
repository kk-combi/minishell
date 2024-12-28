/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:11:06 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 12:39:52 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **p, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(p[i]);
	free(p);
	return ;
}

static int	set_word(char const *str, char c, char **p)
{
	size_t	i;
	size_t	j;
	size_t	cur;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == c))
			i++;
		cur = i;
		while (str[i] && (str[i] != c))
			i++;
		if (str[i - 1] && (str[i - 1] != c))
		{
			p[j] = ft_substr(str, cur, i - cur);
			if (!p[j])
			{
				free_array(p, j);
				return (0);
			}
		}
		j++;
	}
	return (1);
}

static int	count_split(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (*s != c && *s)
		count++;
	if (*s == 0)
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**p;

	if (!s)
		return (NULL);
	count = count_split(s, c);
	p = (char **)malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (NULL);
	if (count != 0)
	{
		if (!set_word(s, c, p))
			return (NULL);
	}
	p[count] = NULL;
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**result;
// 	char	**result_pointer;
// 	char	*str;
// 	char	charset;

// 	str = "Hello,World!Moutain,,Sea!,wind";
// 	charset = ',';
// 	printf("bf splist: %s\n", str);
// 	result = ft_split(str, charset);
// 	result_pointer = result;
// 	while (*result)
// 	{
// 		printf("%s\n", *result);
// 		free(*result);
// 		result++;
// 	}
// 	free(result_pointer);
// }
