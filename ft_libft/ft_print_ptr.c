/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:35:45 by kasasaki          #+#    #+#             */
/*   Updated: 2024/11/24 12:36:22 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(unsigned long long p)
{
	int	len;
	int	tmp;

	if (!p)
		return (ft_print_str(NULL_PTR));
	len = 0;
	tmp = 0;
	tmp = ft_print_str("0x");
	if (tmp < 0)
		return (-1);
	len += tmp;
	tmp = ft_print_hint((uintptr_t)p, HEX_L_FMT);
	if (tmp < 0)
		return (-1);
	return (len + tmp);
}
