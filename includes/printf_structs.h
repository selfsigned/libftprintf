/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 01:56:57 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/17 21:21:39 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_STRUCTS_H
# define PRINTF_STRUCTS_H

# include "printf.h"

typedef	enum	e_length
{
	Null,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_length;

/*
** Printf argument structure for parsing
**
** ft_printf string format:
** %[flags][width][.precision][length]type
**
*/

typedef struct	s_parg
{
	char		flags[5];
	int			width;
	int			prec;
	t_length	length;
	char		type;
	size_t		convlen;
}				t_parg;

#endif
