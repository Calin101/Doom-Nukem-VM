/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickups2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:18:03 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 19:32:44 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	check_obj(t_object *object, t_input *data)
{
	t_object	*obj;
	float		dist;

	obj = object;
	while (obj)
	{
		while (obj && !obj->exist)
			obj = obj->next;
		if (!obj)
			return ;
		dist = get3ddist(obj->pos, (t_fdot){.x = 0, .y = 0, .z = 0});
		if (obj->hp <= 0 && obj->type == ENEMI)
			obj->exist = 0;
		if (dist <= 500 && dist > object->dist && obj->type == ENEMI)
			agro(obj, data);
		printf("%f                      %f\n", dist, object->dist);
		if (dist <= object->dist)
			collobj(obj, data);
		obj = obj->next;
	}
}
