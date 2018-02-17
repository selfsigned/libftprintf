/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:15:33 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/17 19:33:13 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	t_parg	init_parg(void)
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

static	size_t		p_length(const char *fmt, t_parg *parg)
{
	if ((fmt[0] == 'h' && fmt[1] == 'h')
		|| (fmt[0] == 'l' && fmt[1] == 'l'))
	{
		parg->length = (fmt[0] == 'h') ? hh : ll;
		return (2);
	}
	if (fmt[0] == 'h' || fmt[0] == 'l')
	{
		parg->length = (fmt[0] == 'h') ? h : l;
		return (1);
	}
	if (fmt[0] == 'j' || fmt[0] == 'z')
	{
		parg->length = (fmt[0] == 'j') ? j : z;
		return (1);
	}
	parg->length = Null;
	return (0);
}

/*
** Printf string syntax:
**  %[flags][width][.precision][length]type
**
**  TBD: flags
*/

t_parg			printf_readarg(size_t i, const char *fmt)
{
	t_parg	parg;

	parg = init_parg();
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
	i += p_length(fmt + i, &parg);
	parg.type = fmt[i++];
	parg.convlen = i;
	return (parg);
}
