/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:35:45 by kasasaki          #+#    #+#             */
/*   Updated: 2024/11/24 12:36:22 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *s)
{
	if (!s)
		return (write(FD_STDOUT, NULL_STR, ft_strlen(NULL_STR)));
	return (write(FD_STDOUT, s, ft_strlen(s)));
}
