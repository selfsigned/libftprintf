/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/20 23:53:44 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

size_t	conv_int(int fd, t_parg parg, va_list ap)
{
	int		n;
	size_t	i;

	n = va_arg(ap, int);
	ft_putnbr_fd(n, fd);
	return (ft_cntdigit(n));
}
