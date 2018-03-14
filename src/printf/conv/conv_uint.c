/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/14 19:25:00 by xperrin          ###   ########.fr       */
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
** (same than left aligned)
**
** Left aligned: (default)
** ' ' | 'prepend' | '0' | itoa(d)
**
** Right aligned:
** 'prepend' | '0' | itoa(d) | ' ': w - p (-prepend?)
*/

static	size_t		l_print(int fd, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	size_t	w;

	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
	while (parg.width-- - size > 0)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
	while (size-- - w > 0)
	{
		ft_putchar_fd('0', fd);
		i++;
	}
	ft_putstr_fd(str, fd);
	return (i);
}

static	size_t		r_print(int fd, char *str, t_parg parg)
{
	int		size;
	size_t	i;
	int		tmp;
	size_t	w;

	w = ft_strlen(str);
	i = w;
	size = (parg.prec > (int)w) ? parg.prec : (int)w;
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
	return (i);
}

static size_t		bloat_print(int fd, intmax_t n, t_parg parg)
{
	char		*str;
	size_t		i;

	if (!parg.prec && !n)
		str = ft_strdup("\0");
	else if (parg.type == 'x')
		str = ft_utoa_base(n, "0123456789abcdef");
	else if (parg.type == 'X')
		str = ft_utoa_base(n, "0123456789ABCDEF");
	else if (parg.type == 'o' || parg.type == 'O')
		if (ft_strchr(parg.flags, '#') && n)
			str = ft_strjoinfreeb("0", ft_utoa_base(n, "01234567"));
		else
			str = ft_utoa_base(n, "01234567");
	else
		str = ft_utoa_base(n, "0123456789");
	i = ft_strlen(str);
	if (!ft_strchr(parg.flags, '-'))
		i = l_print(fd, str, parg);
	else
		i = r_print(fd, str, parg);
	free(str);
	return (i);
}

size_t				conv_uint(int fd, t_parg parg, va_list ap)
{
	uintmax_t	n;
	char		*str;

	n = conv_t_uint(parg, ap);
	if (ft_strchr(parg.flags, '0'))
	{
		parg.prec = parg.width;
		parg.width = 0;
	}
	if (!parg.prec && !n)
		str = ft_strdup("\0");
	else if (parg.type == 'x' || parg.type == 'X')
		str = (parg.type == 'x') ? ft_utoa_base(n, "0123456789abcdef")
			: ft_utoa_base(n, "0123456789ABCDEF");
	else if (parg.type == 'o' || parg.type == 'O')
		str = (ft_strchr(parg.flags, '#') && n) ? ft_strjoinfreeb("0",
				ft_utoa_base(n, "01234567")) : ft_utoa_base(n, "01234567");
	else
		str = ft_utoa_base(n, "0123456789");
	if (!ft_strchr(parg.flags, '-'))
		n = l_print(fd, str, parg);
	else
		n = r_print(fd, str, parg);
	free(str);
	return (n);
}
