/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:05:30 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 21:08:27 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_bzero(result, (nmemb * size));
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>

// void	check(void *result)
// {
// 	if (!result)
// 	{
// 		printf("result is null\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 		printf("memory is initialized\n");
// }

// int	main(void)
// {
// 	int	i;

// 	int *ptr, *p;
// 	ptr = (int *)calloc(500, sizeof(int));
// 	check(ptr);
// 	p = ptr;
// 	i = 0;
// 	while (i < 500)
// 	{
// 		*p = i;
// 		printf("%d ", *p);
// 		p++;
// 		i++;
// 	}
// 	free(ptr);
// 	printf("\n");
// 	check(calloc(0, 0));
// 	check(ft_calloc(0, 0));
// 	return (0);
// }
