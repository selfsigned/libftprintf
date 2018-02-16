/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 01:56:57 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/16 18:09:30 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_STRUCTS_H
# define PRINTF_STRUCTS_H

# include "printf.h"

/*
** Printf argument structure for parsing
**
** ft_printf string format:
** %[flags][width][.precision][length]type
*/
enum			e_flags
{
	sharp,
	zero,
	minus,
	plus,
	space
};

typedef	enum	e_length
{
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_length;

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
