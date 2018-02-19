/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:23:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/19 13:54:13 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	printf_printarg(int fd, t_parg parg, va_list ap)
{
	size_t	i;

	i = 0;
	if (parg.type == '%')
	{
		ft_putchar('%');
		return (1);
	}
	if (ft_strchr("cC", parg.type))
		return (conv_char(fd, parg, ap));
	if (ft_strchr("sS", parg.type))
		return (conv_string(fd, parg, ap));
	if (ft_strchr("dDiuU", parg.type))
		return (0);
	return (i);
}
