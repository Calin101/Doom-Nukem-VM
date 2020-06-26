/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 16:39:55 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 17:06:16 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	maprotp(t_poly *poly, t_fdot rot, t_input *data)
{
	int		i;
	t_poly	*gones;

	gones = poly;
	while (gones)
	{
		i = -1;
		while (++i < 3)
		{
			if (rot.y)
				gones->dot[i] = data->angley == 0 ? gones->rotx[i] :
				applymatpoint(define_yrotmax(data->angley), gones->rotx[i]);
			else
			{
				if (rot.z == 1)
					gones->rotx[i] = applymatpoint(data->rotz, gones->rotx[i]);
				else if (rot.z == -1)
					gones->rotx[i] = applymatpoint(data->minrotz,
					gones->rotx[i]);
				data->nbrtour = 1;
			}
		}
		gones = gones->next;
	}
}

void	maprotateallp(t_fdot rot, t_input *data)
{
	t_object *obj;

	obj = data->obj;
	while (obj)
	{
		maprotp(obj->poly, rot, data);
		redefinevector(obj->poly);
		if (rot.y)
			obj->pos = applymatpoint(define_yrotmax(data->angley), obj->posrx);
		else
		{
			if (rot.z == 1)
				obj->posrx = applymatpoint(data->rotz, obj->posrx);
			else if (rot.z == -1)
				obj->posrx = applymatpoint(data->minrotz, obj->posrx);
		}
		obj = obj->next;
	}
	maprotp(data->map, rot, data);
	rot_sky(data, rot);
	redefinevector(data->map);
}
