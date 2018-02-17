/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helpers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:02:58 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/17 19:32:57 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HELPERS_H
# define PRINTF_HELPERS_H

# include "printf.h"
#include <stdarg.h>

t_parg		printf_readarg(size_t i, const char *fmt);

#endif
