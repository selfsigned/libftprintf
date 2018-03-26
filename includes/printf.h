/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:57:28 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/26 01:26:06 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include "printf_structs.h"
# include "printf_conv.h"
# include <wchar.h>

# define CONV_LST "sSpdDioOuUxXcC%b"

/*
** printf is a variadic function (look it up on google)
*/
# include <stdarg.h>

/*
** Needed for intmax_t
*/
# include <inttypes.h>

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);

/*
** Parsing helpers
*/

t_parg			printf_readarg(size_t i, const char *fmt);
size_t			printf_printarg(int fd, t_parg parg, va_list ap);

#endif
