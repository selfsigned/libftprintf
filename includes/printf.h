/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:57:28 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/15 23:55:29 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include "printf_conv.h"
# include "printf_helpers.h"

# define CONV_LST "sSpdDioOuUxXcC%"
/*
** printf is a variadic function (look it up on google)
*/
# include <stdarg.h>
char			*ft_sprintf(const char *format, ...);
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
char			*ft_vsprintf(const char *format, va_list ap);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);

typedef struct	s_parg
{
	int			width;
	int			prec;
	char		sign;
	int			flen;
}				t_parg;

#endif
