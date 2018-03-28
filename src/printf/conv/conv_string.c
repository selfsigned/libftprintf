/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:54:58 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/28 21:41:05 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static size_t	wstrlen(wchar_t *s)
{
	size_t			l;
	unsigned char	t[4];

	l = 0;
	while (*s)
		l += conv_unicode(t, *s++);
	return (l);
}

static size_t	putwstrn(wchar_t *s, size_t n, int fd)
{
	size_t			i;
	size_t			clen;
	unsigned char	c[4];

	i = 0;
	if (!s)
	{
		write(fd, "(null)", n);
		return (n);
	}
	while (*s && i < n)
	{
		clen = conv_unicode(c, *s++);
		if (i + clen <= n)
			write(fd, c, clen);
		else
			break ;
		i += clen;
	}
	return (i);
}

static size_t	conv_ustring(int fd, t_parg parg, va_list ap)
{
	wchar_t	*u;
	size_t	i;
	size_t	d;

	i = 0;
	u = va_arg(ap, wchar_t*);
	d = wstrlen((u) ? u : L"(null)");
	parg.prec = (parg.prec < 0 || d < (size_t)parg.prec) ? d : parg.prec;
	if (ft_strchr(parg.flags, '-'))
		i = putwstrn(u, parg.prec, fd);
	while (parg.width - parg.prec > 0)
	{
		parg.width--;
		ft_putchar_fd((ft_strchr(parg.flags, '0')) ? '0' : ' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		i += putwstrn(u, parg.prec, fd);
	return (i);
}

size_t			conv_string(int fd, t_parg parg, va_list ap)
{
	char	*s;
	size_t	i;

	i = 0;
	if (parg.type == 'S' || parg.length == l)
		return (conv_ustring(fd, parg, ap));
	s = va_arg(ap, char*);
	s = (!s) ? "(null)" : s;
	parg.prec = (parg.prec < 0 || ft_strlen(s) < (size_t)parg.prec)
		? (int)ft_strlen(s) : parg.prec;
	if (ft_strchr(parg.flags, '-'))
		write(fd, s, parg.prec);
	while (parg.width - parg.prec > 0)
	{
		parg.width--;
		ft_putchar_fd((ft_strchr(parg.flags, '0')) ? '0' : ' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		write(fd, s, parg.prec);
	return (i + parg.prec);
}
