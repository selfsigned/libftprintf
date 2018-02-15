/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 23:57:48 by xperrin           #+#    #+#             */
/*   Updated: 2018/02/16 00:00:18 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_sprintf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return(ft_vsprintf(format, ap));
}
