/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:47:09 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 16:47:19 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

float	get3ddist(t_fdot a, t_fdot b)
{
	float dx;
	float dy;
	float dz;

	dx = b.x - a.x;
	dy = b.y - a.y;
	dz = b.z - a.z;
	return (sqrtf(dx * dx + dy * dy + dz * dz));
}

float	getpow3ddist(t_fdot a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

t_fdot	vectorial_product(t_fdot a, t_fdot b)
{
	t_fdot u;

	u.x = a.y * b.z - a.z * b.y;
	u.y = a.z * b.x - a.x * b.z;
	u.z = a.x * b.y - a.y * b.x;
	return (u);
}

void	getobjplans(t_input *data)
{
	t_object *obj;

	obj = data->obj;
	while (obj)
	{
		get_plans(obj->poly);
		obj = obj->next;
	}
}

void	get_plans(t_poly *poly)
{
	t_fdot vectu;

	while (poly)
	{
		vectu = vectorial_product(getvect(poly->dot[0],
		poly->dot[1]), getvect(poly->dot[0], poly->dot[2]));
		poly->a = vectu.x;
		poly->b = vectu.y;
		poly->c = vectu.z;
		poly->d = -(poly->a * poly->dot[0].x + poly->b *
		poly->dot[0].y + poly->c * poly->dot[0].z);
		poly = poly->next;
	}
}
