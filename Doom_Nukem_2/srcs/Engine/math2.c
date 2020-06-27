/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:46:41 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 14:16:10 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	redefineobj(t_input *data)
{
	t_object *obj;

	obj = data->obj;
	while (obj)
	{
		redefinevector(obj->poly);
		obj = obj->next;
	}
}

void	redefinevector(t_poly *poly)
{
	while (poly)
	{
		poly->vab = getvect(poly->dot[0], poly->dot[1]);
		poly->vbc = getvect(poly->dot[1], poly->dot[2]);
		poly->vac = getvect(poly->dot[0], poly->dot[2]);
		poly->scaleab = scale(poly->vab, poly->vab);
		poly->scaleac = scale(poly->vac, poly->vac);
		poly->scaleabac = scale(poly->vab, poly->vac);
		poly->vba = getvect(poly->dot[1], poly->dot[0]);
		poly->vcb = getvect(poly->dot[2], poly->dot[1]);
		poly->vca = getvect(poly->dot[2], poly->dot[0]);
		poly->den1 = (-poly->vab.y * poly->vbc.z + poly->vbc.y * poly->vab.z);
		poly->den2 = (-poly->vab.x * poly->vbc.y + poly->vbc.x * poly->vab.y);
		poly->den3 = (-poly->vab.z * poly->vbc.x + poly->vbc.z * poly->vab.x);
		poly = poly->next;
	}
}

t_fdot	getvect(t_fdot a, t_fdot b)
{
	return ((t_fdot){.x = b.x - a.x, .y = b.y - a.y, .z = b.z - a.z});
}

float	magnitude(t_fdot a)
{
	return (sqrtf(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_2d	get2dvect(t_2d a, t_2d b)
{
	return ((t_2d){.x = b.x - a.x, .y = b.y - a.y});
}
