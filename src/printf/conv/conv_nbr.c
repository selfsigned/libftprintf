/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/24 02:14:57 by xperrin          ###   ########.fr       */
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
	return (r);
}

size_t	conv_nbr(int fd, t_parg parg, va_list ap)
{
	char		*str;
	intmax_t	n;
	char		prepend;
	size_t		i;
	size_t		w;

	prepend = '\0';
	n = intconv(ap, parg.length);
	if (ft_strchr("idD", parg.type))
		str = ft_itoa_base(n, "0123456789");
	else if (parg.type == 'X')
		str = ft_itoa_base(n, "0123456789ABCDEF");
	else
		str = ft_itoa_base(n, "0123456789abcdef");
	w = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	i = w;
	return (i);
}
