/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:28:43 by kasasaki          #+#    #+#             */
/*   Updated: 2024/11/24 12:36:43 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_hex_len(uintptr_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	print_hint(uintptr_t n, char fmt)
{
	uintptr_t	r;

	r = n % 16;
	n /= 16;
	if (n < 0)
		return (-1);
	if (n > 0)
		print_hint(n, fmt);
	if (r < 10)
		return (ft_print_char(r + '0'));
	if (fmt == HEX_L_FMT)
		return (ft_print_char('a' + (r - 10)));
	return (ft_print_char('A' + (r - 10)));
}

int	ft_print_hint(uintptr_t n, char fmt)
{
	if (print_hint(n, fmt) < 0)
		return (-1);
	return (calc_hex_len(n));
}
