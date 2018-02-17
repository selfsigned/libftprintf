/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:41:49 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/17 19:34:37 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	size_t	i;
	int		res;
	t_parg	parg;

	(void)ap;
	res = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parg = printf_readarg(i, format);
			/* ft_putstr(parg.flags); */
			/* ft_putnbr(parg.width); */
			/* ft_putnbr(parg.length); */
			i = parg.convlen;
		}
		else
		{
			write(fd, format + i, 1);
			i++;
			res += 1;
		}
	}
	return (res);
}
