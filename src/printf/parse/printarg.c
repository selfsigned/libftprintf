/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:23:40 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/24 01:44:53 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	printf_printarg(int fd, t_parg parg, va_list ap)
{
	if (ft_strchr("c%", parg.type))
		return (conv_char(fd, parg, ap));
	else if (parg.type == 's')
		return (conv_string(fd, parg, ap));
	else if (ft_strchr("dDixX", parg.type))
		return (conv_nbr(fd, parg, ap));
	return (0);
}
