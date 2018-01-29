/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:41:49 by xperrin           #+#    #+#             */
/*   Updated: 2018/01/29 23:31:54 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdlib.h>

/*
** len[0] = len to next conv
** len[1] = total printf len
*/

static int		_freeret(int *tofree)
{
	free(tofree);
	return (-1);
}

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		*len;
	int		res;

	len = ft_memalloc(sizeof(int) * 2);
	while (*format)
	{
		if (*format++ == '%')
		{
			len = printf_readarg(fd, len, format, ap);
			if (len[1] == -1)
				return (_freeret(len));
			format = format + len[0];
		}
		len[0] = ft_strrlen(format, '%');
		len[1] += len[0];
		write(fd, format, len[0]);
		format += len[0];
	}
	res = len[1];
	free(len);
	return (res);
}
