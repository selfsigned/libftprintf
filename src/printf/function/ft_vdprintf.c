/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:41:49 by xperrin           #+#    #+#             */
/*   Updated: 2018/01/29 09:23:48 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "unistd.h"

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	size_t		lentoconv;

	(void)ap;
	while (*format)
	{
		if (*format == '%')
			format++;
		lentoconv = ft_strrlen(format, '%');
		write(fd, format, lentoconv);
		format += lentoconv;
	}
	return (lentoconv);
}
