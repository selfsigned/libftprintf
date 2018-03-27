/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 01:11:32 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/27 02:53:32 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	conv_unicode(unsigned char *d, unsigned int n)
{
	ft_printf("binary input: %b\n", n);
	if (n <= 0x7F)
	{
		d[0] = n;
		return (1);
	}
	else
	{
		d[0] = (n >> 6) + 0xC0;
		d[1] = (n & 0x3f) + 0x80;
		ft_printf("binary output result: %b %b\n", d[0], d[1]);
		return (2);
	}
}
