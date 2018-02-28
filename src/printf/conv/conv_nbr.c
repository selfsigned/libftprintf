/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/28 18:35:21 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <stdlib.h>

static	intmax_t	intconv(va_list ap, t_parg parg)
{
	intmax_t r;

	r = va_arg(ap, intmax_t);
	if (parg.type == 'D')
		r = (long int)r;
	else if (parg.length == hh)
		r = (char)r;
	else if (parg.length == h)
		r = (short int)r;
	else if (parg.length == l)
		r = (long int)r;
	else if (parg.length == ll)
		r = (long long)r;
	else if (parg.length == z)
		r = (size_t)r;
	else if (parg.length == j)
		r = (intmax_t)r;
	else if (parg.length == j)
		r = (intmax_t)r;
	else
		r = (int)r;
	return (r);
}

/*
** d = argument ; f = flag ; w = width ; p = precision
**
** Three cases:
**
** Precision only:
** p > w and p > d, basically just zeroes
** (might be the same than left aligned)
**
** Left aligned: (default)
** ' ' | 'prepend' | '0' | itoa(d)
**
** Right aligned:
** 'prepend' | '0': p - d | itoa(d) | ' ': w - p (-prepend?)
*/

size_t				bloat_print(int fd, intmax_t n, char prepend, t_parg parg)
{
	char		*str;
	size_t		w;
	size_t		i;
	int			size;
	int			tmp;

	if (ft_strchr("idD", parg.type))
		str = ft_itoa_base(n, "0123456789");
	else if (parg.type == 'X')
		str = ft_itoa_base(n, "0123456789ABCDEF");
	else
		str = ft_itoa_base(n, "0123456789abcdef");
	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	size = (prepend) ? size + 1 : size;
	if (parg.prec >= parg.width && parg.prec > (int)w)
	{
		(prepend) ? ft_putchar_fd(prepend, fd) : (void)42;
		i = (!(i - 1)) ? i : i - 1;
		while (i++ && parg.prec-- > (int)w)
			ft_putchar_fd('0', fd);
		ft_putstr_fd(str, fd);
	}
	else if (!ft_strchr(parg.flags, '-'))
	{
		while (parg.width-- - size > 0)
		{
			ft_putchar_fd(' ', fd);
			i++;
		}
		(prepend) ? ft_putchar_fd(prepend, fd) : (void)42;
		size = (prepend) ? size - 1 : size;
		while (size-- - w > 0)
		{
			ft_putchar_fd('0', fd);
			i++;
		}
		ft_putstr_fd(str, fd);
	}
	else
	{
		(prepend) ? ft_putchar_fd(prepend, fd) : (void)42;
		tmp = size;
		while (size-- - w > 0)
		{
			ft_putchar_fd('0', fd);
			i++;
		}
		ft_putstr_fd(str, fd);
		while (parg.width-- - tmp > 0)
		{
			ft_putchar_fd(' ', fd);
			i++;
		}
	}
	free(str);
	return (i);
}

size_t				conv_nbr(int fd, t_parg parg, va_list ap)
{
	intmax_t	n;
	char		prepend;
	size_t		w;

	prepend = '\0';
	prepend = ft_strchr(parg.flags, ' ') ? ' ' : prepend;
	prepend = ft_strchr(parg.flags, '+') ? '+' : prepend;
	n = intconv(ap, parg);
	if (n < 0)
	{
		n = -n;
		prepend = '-';
	}
	if (ft_strchr(parg.flags, '0'))
	{
		parg.prec = (prepend) ? parg.width - 1 : parg.width;
		parg.width = 0;
	}
	w = bloat_print(fd, n, prepend, parg);
	return ((prepend) ? w + 1 : w);
}
