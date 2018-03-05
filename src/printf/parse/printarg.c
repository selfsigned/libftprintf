/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:23:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/05 12:49:03 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	printf_printarg(int fd, t_parg parg, va_list ap)
{
	if (ft_strchr("c%", parg.type))
		return (conv_char(fd, parg, ap));
	else if (parg.type == 's')
		return (conv_string(fd, parg, ap));
	else if (ft_strchr("idD", parg.type))
		return (conv_int(fd, parg, ap));
	else if (ft_strchr("uUxX", parg.type))
		return (conv_uint(fd, parg, ap));
	return (0);
}
