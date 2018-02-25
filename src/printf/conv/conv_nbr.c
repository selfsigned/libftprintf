/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/25 02:06:37 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdlib.h>

static	intmax_t	intconv(va_list ap, t_length len)
{
	intmax_t r;

	r = va_arg(ap, intmax_t);
	if (len == hh)
		r = (char)r;
	else if (len == h)
		r = (short)r;
	else if (len == l)
		r = (long int)r;
	else if (len == ll)
		r = (long long)r;
	else if (len == z)
		r = (size_t)r;
	else if (len == j)
		r = (intmax_t)r;
	else if (len == j)
		r = (intmax_t)r;
	else
		r = (int)r;
	return (r);
}

size_t				bloat_print(int fd, intmax_t n, char prepend, t_parg parg)
{
	char		*str;
	size_t		w;

	if (ft_strchr("idD", parg.type))
		str = ft_itoa_base(n, "0123456789");
	else if (parg.type == 'X')
		str = ft_itoa_base(n, "0123456789ABCDEF");
	else
		str = ft_itoa_base(n, "0123456789abcdef");
	w = ft_strlen(str);
	ft_putchar_fd(prepend, fd);
	ft_putstr_fd(str, fd);
	free(str);
	return (w);
}

size_t				conv_nbr(int fd, t_parg parg, va_list ap)
{
	intmax_t	n;
	char		prepend;
	size_t		w;

	prepend = '\0';
	prepend = ft_strchr(parg.flags, ' ') ? ' ' : prepend;
	prepend = ft_strchr(parg.flags, '+') ? '+' : prepend;
	n = intconv(ap, parg.length);
	if (n < 0)
	{
		n = -n;
		prepend = '-';
	}
	w = bloat_print(fd, n, prepend, parg);
	return ((prepend) ? w + 1 : w);
}
