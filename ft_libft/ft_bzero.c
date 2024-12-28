/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:09:26 by kasasaki          #+#    #+#             */
/*   Updated: 2024/10/27 20:42:02 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	greeting[11] = "HelloWorld!";

// 	printf("Before clearing: %s\n", greeting);
// 	ft_bzero(greeting, sizeof(greeting));
// 	printf("After clearing: %s\n", greeting);
// }
