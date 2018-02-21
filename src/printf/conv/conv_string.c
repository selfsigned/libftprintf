/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:54:58 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/21 00:04:36 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

size_t			conv_string(int fd, t_parg parg, va_list ap)
{
	char	*s;
	size_t	i;

	i = 0;
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
