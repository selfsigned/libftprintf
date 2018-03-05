/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/05 12:51:17 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

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
** 'prepend' | '0' | itoa(d) | ' ': w - p (-prepend?)
*/

static	size_t		l_print(int fd,  char prepend, char *str, t_parg parg, int w)
{
	int		size;
	size_t	i;

	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	size = (prepend) ? size + 1 : size;
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
	return (i);
}

static	size_t		r_print(int fd, char prepend, char *str, t_parg parg, int w)
{
	int		size;
	size_t	i;
	int		tmp;

	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	size = (prepend) ? size + 1 : size;
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
	return(i);
}

static size_t		bloat_print(int fd, intmax_t n, char prepend, t_parg parg)
{
	char		*str;
	size_t		w;
	size_t		i;
	int			size;

	if (parg.type == 'x')
		str = ft_itoa_base(n, "0123456789abcdef");
	else if (parg.type == 'X')
		str = ft_itoa_base(n, "0123456789ABCDEF");
	else
		str = ft_itoa_base(n, "0123456789");
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
		i = l_print(fd, prepend, str, parg, w);
	else
		i = r_print(fd, prepend, str, parg, w);
	free(str);
	return (i);
}

size_t				conv_uint(int fd, t_parg parg, va_list ap)
{
	intmax_t	n;
	char		prepend;
	size_t		w;

	prepend = '\0';
	prepend = ft_strchr(parg.flags, ' ') ? ' ' : prepend;
	prepend = ft_strchr(parg.flags, '+') ? '+' : prepend;
	n = conv_t_uint(parg, ap);
	if (ft_strchr(parg.flags, '0'))
	{
		parg.prec = (prepend) ? parg.width - 1 : parg.width;
		parg.width = 0;
	}
	w = bloat_print(fd, n, prepend, parg);
	return ((prepend) ? w + 1 : w);
}
