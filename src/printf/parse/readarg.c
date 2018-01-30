/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:15:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/01/30 17:11:44 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int *_leniter(int *len)
{
	len[0] += 1;
	len[1] += 1;
	return (len);
}

int		*printf_readarg(int fd, int *len, const char *fmt, va_list ap)
{
	if (*fmt == '%')
	{
		ft_putchar_fd('%', fd);
		len = _leniter(len);
	}
	(void)fmt;
	(void)ap;
	return (len);
}
