/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:38:35 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/21 01:22:17 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

size_t	conv_int(int fd, t_parg parg, va_list ap)
{
	char	sign;
	int		n;
	size_t	i;
	size_t	w;

	sign = '\0';
	(void)parg.width;
	n = va_arg(ap, int);
	w = ft_cntdigit(n);
	ft_putnbr_fd(n, fd);
	i = w;
	return (i);
}
