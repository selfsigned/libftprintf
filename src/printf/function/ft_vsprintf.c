/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 00:01:07 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/16 00:23:21 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_vsprintf(const char *format, va_list ap)
{
	char	*res;

	res = ft_strdup(format);
	return (res);
}
