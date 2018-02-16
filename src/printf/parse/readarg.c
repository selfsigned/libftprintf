/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:15:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/16 01:21:00 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		printf_readarg(char *dst, const char *fmt, va_list ap)
{
	int		len;

	len = 1;
	if (fmt[len] == '%')
	{
		dst = ft_strjoinfree(dst, &fmt[len]);
	}
	(void)fmt;
	(void)ap;
	return (len);
}
