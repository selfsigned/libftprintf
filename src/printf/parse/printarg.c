/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:23:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/19 15:46:13 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	printf_printarg(int fd, t_parg parg, va_list ap)
{
	if (ft_strchr("cC%", parg.type))
		return (conv_char(fd, parg, ap));
	if (ft_strchr("sS", parg.type))
		return (conv_string(fd, parg, ap));
	if (ft_strchr("dDiuU", parg.type))
		return (0);
	return (0);
}
