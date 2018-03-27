/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 01:11:32 by xperrin           #+#    #+#             */
/*   Updated: 2018/03/27 03:40:51 by xperrin          ###   ########.fr       */
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
	else if (n <= 0x7FF)
	{
		d[0] = (n >> 6) + 0xC0;
		d[1] = (n & 0x3f) + 0x80;
		ft_printf("binary output result: %b %b\n", d[0], d[1]);
		return (2);
	}
	/* PLACEHOLDERS */
	else if (n <= 0xFFFF)
	{
		d[0] = (n >> 12) + 0xC0;
		d[1] = (n >> 6) + 0xC0;
		d[2] = (n & 0x3f) + 0x80;
		ft_printf("binary output result: %b %b %b\n", d[0], d[1], d[2]);
		return(3);
	}
	else if (n <= 0x10FFFF)
	{
		d[0] = (n >> 16) + 0xC0;
		d[1] = (n >> 12) + 0xC0;
		d[2] = (n >> 6) + 0xC0;
		d[3] = (n & 0x3f) + 0x80;
		ft_printf("binary output result: %b %b %b %b\n", d[0], d[1], d[2], d[3]);
	}
	ft_printf("something went wrong");
	return(1);
}
