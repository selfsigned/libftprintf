/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:41:49 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/16 00:20:27 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*res;
	size_t	reslen;

	res = ft_vsprintf(format, ap);
	reslen = ft_strlen(res);
	write(fd, res, reslen);
	return (reslen);
}
