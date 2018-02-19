/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:42:25 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/19 14:11:00 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static	size_t	display_char(int fd, t_parg parg, va_list ap)
{
	char	c;
	size_t	i;

	i = 1;
	c = va_arg(ap, int);
	if (ft_strchr(parg.flags, '-'))
		ft_putchar_fd(c, fd);
	parg.width--;
	while (parg.width > 0)
	{
		parg.width--;
		ft_putchar_fd(' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		ft_putchar_fd(c, fd);
	return (i);
}

size_t	conv_char(int fd, t_parg parg, va_list ap)
{
	if (parg.type == 'c' && !ft_strchr(parg.flags, 'l'))
		return (display_char(fd, parg, ap));
	return (0);
}
