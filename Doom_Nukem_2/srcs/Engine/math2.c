/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:46:41 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 16:46:54 by user42           ###   ########lyon.fr   */
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
		poly->vAB = getvect(poly->dot[0], poly->dot[1]);
		poly->vBC = getvect(poly->dot[1], poly->dot[2]);
		poly->vAC = getvect(poly->dot[0], poly->dot[2]);
		poly->scaleAB = scale(poly->vAB, poly->vAB);
		poly->scaleAC = scale(poly->vAC, poly->vAC);
		poly->scaleABAC = scale(poly->vAB, poly->vAC);
		poly->vBA = getvect(poly->dot[1], poly->dot[0]);
		poly->vCB = getvect(poly->dot[2], poly->dot[1]);
		poly->vCA = getvect(poly->dot[2], poly->dot[0]);
		poly->den1 = (-poly->vAB.y * poly->vBC.z + poly->vBC.y * poly->vAB.z);
		poly->den2 = (-poly->vAB.x * poly->vBC.y + poly->vBC.x * poly->vAB.y);
		poly->den3 = (-poly->vAB.z * poly->vBC.x + poly->vBC.z * poly->vAB.x);
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
