/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/12 18:12:16 by xperrin          ###   ########.fr       */
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
		str = (ft_strchr(parg.flags, '#')) ?
				ft_strjoinfreeb("0x", ft_utoa_base(n, "0123456789abcdef")) :
				ft_utoa_base(n, "0123456789abcdef");
	else if (parg.type == 'X')
		str = (ft_strchr(parg.flags, '#')) ?
				ft_strjoinfreeb("0x", ft_utoa_base(n, "0123456789ABCDEF")) :
				ft_utoa_base(n, "0123456789ABCDEF");
	else if (parg.type == 'o' || parg.type == 'O')
		if (ft_strchr(parg.flags, '#'))
			str = ft_strjoinfreeb("0", ft_utoa_base(n, "01234567"));
		else
			str = ft_utoa_base(n, "01234567");
	else if (parg.type == 'p')
		str = ft_strjoinfreeb("0x", ft_utoa_base(n, "0123456789abcdef"));
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
	intmax_t	n;
	size_t		w;

	n = conv_t_uint(parg, ap);
	if (ft_strchr(parg.flags, '0'))
	{
		parg.prec = parg.width;
		parg.width = 0;
	}
	w = bloat_print(fd, n, parg);
	return(w);
}
