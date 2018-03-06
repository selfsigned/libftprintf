/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/06 18:42:17 by xperrin          ###   ########.fr       */
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

static	size_t		l_print(int fd, char prepend, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	size_t	w;

	w = ft_strlen(str);
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
	free(str);
	return ((prepend) ? i + 1 : i);
}

static	size_t		r_print(int fd, char prepend, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	int		tmp;
	size_t	w;

	w = ft_strlen(str);
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
	free(str);
	return ((prepend) ? i + 1 : i);
}

static size_t		prec_print(int fd, char prepend, char *str, t_parg parg)
{
	size_t		w;
	size_t		i;
	int			size;

	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	size = (prepend) ? size + 1 : size;
	(prepend) ? ft_putchar_fd(prepend, fd) : (void)42;
	i = (!(i - 1)) ? i : i - 1;
	while (i++ && parg.prec-- > (int)w)
		ft_putchar_fd('0', fd);
	ft_putstr_fd(str, fd);
	free(str);
	return ((prepend) ? i + 1 : i);
}

size_t				conv_int(int fd, t_parg parg, va_list ap)
{
	intmax_t	n;
	char		prepend;
	char		*str;

	prepend = '\0';
	prepend = ft_strchr(parg.flags, ' ') ? ' ' : prepend;
	prepend = ft_strchr(parg.flags, '+') ? '+' : prepend;
	n = conv_t_int(parg, ap);
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
	str = ft_itoa_base(n, "0123456789");
	if (parg.prec >= parg.width && parg.prec > (int)ft_strlen(str))
		return (prec_print(fd, prepend, str, parg));
	else if (!ft_strchr(parg.flags, '-'))
		return (l_print(fd, prepend, str, parg));
	else
		return (r_print(fd, prepend, str, parg));
}
