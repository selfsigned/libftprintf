/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:43:31 by xperrin           #+#    #+#             */
/*   Updated: 2017/10/04 19:43:41 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int chr)
{
	if (chr >= '0' && '9' >= chr)
		return (1);
	return (0);
}
