/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:07:29 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/24 01:28:46 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONV_H
# define PRINTF_CONV_H

# include "printf.h"
# include <stdarg.h>

size_t	conv_char(int fd, t_parg parg, va_list ap);
size_t	conv_string(int fd, t_parg parg, va_list ap);
size_t	conv_nbr(int fd, t_parg parg, va_list ap);

#endif
