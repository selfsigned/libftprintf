/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:54:58 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/18 21:34:34 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static	size_t	display_string(int fd, t_parg parg, va_list ap)
{
	char	*s;
	size_t	i;

	i = 0;
	s = va_arg(ap, char*);
	parg.prec = (parg.prec < 0 || ft_strlen(s) < (size_t)parg.prec) ?
		ft_strlen(s) : parg.prec;
	if (ft_strchr(parg.flags, '-'))
		write(fd, s, parg.prec);
	while (parg.width - parg.prec > 0)
	{
		parg.width--;
		ft_putchar_fd(' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		write(fd, s, parg.prec);
	return (i + parg.prec);
}

size_t			conv_string(int fd, t_parg parg, va_list ap)
{
	if (parg.type == 's' && !ft_strchr(parg.flags, 'l'))
		return (display_string(fd, parg, ap));
	return (0);
}
