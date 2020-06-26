/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:43:50 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/26 16:47:24 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		solv_equ(t_fdot e1, t_fdot e2, t_fdot *sol)
{
	float tmp;

	if (!(tmp = e2.x * e1.y - e1.x * e2.y))
		return (0);
	tmp = 1. / tmp;
	sol->x = (e2.y * e1.z - e1.y * e2.z) * tmp;
	sol->y = (e1.x * e2.z - e2.x * e1.z) * tmp;
	return (1);
}

float	scale(t_fdot a, t_fdot b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
	return (fmaf(a.x, b.x, fmaf(a.y, b.y, fmaf(a.z, b.z, 0))));
}

t_fdot	fix_vec(t_fdot vec)
{
	t_fdot des;

	des.x = vec.x;
	des.y = vec.y;
	des.z = vec.z;
	if (des.x <= 0.005)
		des.x = 0.f;
	if (des.y <= 0.005)
		des.y = 0.f;
	if (des.z <= 0.005)
		des.z = 0.f;
	return (des);
}

t_fdot	vectoriel_product(t_fdot v1, t_fdot v2)
{
	return ((t_fdot){v1.y * v2.z - v1.z * v2.y,\
						v1.z * v2.x - v1.x * v2.z,\
						v1.x * v2.y - v1.y * v2.x});
}
