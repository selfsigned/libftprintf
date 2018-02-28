/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:07:29 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/28 18:44:41 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONV_H
# define PRINTF_CONV_H

# include "printf.h"
# include <stdarg.h>

intmax_t	conv_t_int(va_list ap, t_parg parg);
intmax_t	conv_t_uint(va_list ap, t_parg parg);

size_t		conv_char(int fd, t_parg parg, va_list ap);
size_t		conv_string(int fd, t_parg parg, va_list ap);
size_t		conv_int(int fd, t_parg parg, va_list ap);

#endif
