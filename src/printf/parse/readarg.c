/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:15:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/16 18:22:06 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	t_parg	init_parg()
{
	t_parg	parg;

	parg.width = 0;
	parg.prec = 0;
	parg.type = '\0';
	return (parg);
}

/*
** parsing the length
*/

static	size_t		p_length(const char *fmt, t_parg parg)
{
	size_t	l;

	l = 0;
	if ((fmt[l] == 'h' && fmt[l + 1] == 'h') || (fmt[l] == 'l' && fmt[l + 1] == 'l'))
	{}
	return (l);
}

/*
** Printf string syntax:
**  %[flags][width][.precision][length]type
**
**  TBD: flags
*/

t_parg			printf_readarg(size_t i, const char *fmt, va_list ap)
{
	t_parg	parg;

	parg = init_parg();
	if (fmt[i] == '%')
		parg.type = '%';
	if (ft_isdigit(fmt[i]))
	{
		parg.width = ft_atoi(fmt + i);
		i += ft_cntdigit(parg.width);
	}
	if (fmt[i] == '.')
	{
		parg.prec = ft_atoi(fmt + 1 + i++);
		i += ft_cntdigit(parg.prec);
	}
	i += p_length(fmt + i, parg);
	/* if (ft_strchr("hljz", fmt[i])) */
	/* { */
	/* 	parg.length[0] = fmt[i]; */
	/* 	if ((fmt[i++] == 'h' && fmt[i] == 'h') || (fmt[i - 1] == 'l' && fmt[i] == 'l')) */
	/* 		parg.length[1] = fmt[i++]; */
	/* } */
	parg.type = fmt[i++];
	parg.convlen = i;
	return (parg);
}
