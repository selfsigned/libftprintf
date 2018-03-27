/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:42:25 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/27 02:47:51 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

static	size_t	conv_uchar(int fd, t_parg parg, va_list ap)
{
	unsigned char	u[4];
	size_t			w;

	(void)parg.type;
	w = conv_unicode(u, va_arg(ap, wchar_t));
	write(fd, u, w);
	return(w);
}

size_t			conv_char(int fd, t_parg parg, va_list ap)
{
	char	c;
	size_t	i;

	i = 1;
	if (parg.type == 'C' || ft_strchr(parg.flags, 'l'))
			return(conv_uchar(fd, parg, ap));
	c = (parg.type == '%') ? parg.type : va_arg(ap, int);
	if (ft_strchr(parg.flags, '-'))
		ft_putchar_fd(c, fd);
	parg.width--;
	while (parg.width > 0)
	{
		parg.width--;
		ft_putchar_fd((ft_strchr(parg.flags, '0')) ? '0' : ' ', fd);
		i++;
	}
	if (!ft_strchr(parg.flags, '-'))
		ft_putchar_fd(c, fd);
	return (i);
}
