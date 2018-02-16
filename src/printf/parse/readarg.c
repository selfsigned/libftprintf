/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:15:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/16 02:45:24 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Printf string syntax:
**  %[parameter][flags][width][.precision][length]type
*/

t_parg		printf_readarg(size_t i, const char *fmt, va_list ap)
{
	t_parg	parg;

	if (*fmt == '%')
	{
	}
	return (parg);
}
