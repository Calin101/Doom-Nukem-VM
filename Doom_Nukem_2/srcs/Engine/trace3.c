/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:28:48 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 18:29:18 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		checkzero(float a, float inter)
{
	return ((a < (0 + inter) && a > (0 - inter)) ? 1 : 0);
}

int		tallnomin(int a, int b)
{
	int	e;
	int	r;

	e = a;
	r = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a >= b)
		return (a);
	return (b);
}
