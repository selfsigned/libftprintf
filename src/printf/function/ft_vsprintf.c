/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 00:01:07 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/16 01:15:46 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_vsprintf(const char *fmt, va_list ap)
{
	char	*res;
	size_t	lento;

	lento = ft_strrlen(fmt, '%');
	res = ft_strndup(fmt, lento);
	fmt += lento;
	while (*fmt)
	{
		if (*fmt == '%')
			fmt += printf_readarg(res, fmt, ap);
		else
		{
			res = ft_strjoinfree(res, &*fmt);
			fmt++;
		}

	}
	return (res);
}
