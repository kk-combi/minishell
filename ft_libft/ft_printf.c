/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasasaki <kasasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:36:13 by kasasaki          #+#    #+#             */
/*   Updated: 2024/11/24 12:36:22 by kasasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_str(const char **start, const char **s)
{
	while (**s && **s != '%')
		(*s)++;
	return (write(1, *start, *s - *start));
}

static int	print_fmt(va_list args, const char **s)
{
	int	n;

	(*s)++;
	n = 0;
	if (**s == 'c')
		n = ft_print_char(va_arg(args, int));
	else if (**s == 's')
		n = ft_print_str(va_arg(args, char *));
	else if (**s == 'p')
		n = ft_print_ptr(va_arg(args, uintptr_t));
	else if (**s == 'd' || **s == 'i')
		n = ft_print_int(va_arg(args, int));
	else if (**s == 'u')
		n = ft_print_uint(va_arg(args, unsigned int));
	else if (**s == 'x' || **s == 'X')
		n = ft_print_hint(va_arg(args, unsigned int), **s);
	else if (**s == '%')
		n = ft_print_char('%');
	else
		return (-1);
	(*s)++;
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			n;
	int			tmp;
	const char	*start;

	if (!s)
		return (-1);
	n = 0;
	va_start(args, s);
	while (*s)
	{
		start = s;
		if (*start != '%')
			tmp = print_str(&start, &s);
		else
			tmp = print_fmt(args, &s);
		if (tmp < 0)
			return (-1);
		n += tmp;
	}
	va_end(args);
	return (n);
}
