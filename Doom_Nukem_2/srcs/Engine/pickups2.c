/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pickups2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 17:18:03 by user42            #+#    #+#             */
/*   Updated: 2020/06/27 15:42:07 by user42           ###   ########lyon.fr   */
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
		dist = getpow3ddist(obj->pos);
		if (obj->hp <= 0 && obj->type == ENEMI)
			obj->exist = 0;
		if (dist <= 500 && dist > 20 && obj->type == ENEMI)
			agro(obj, data);
		//printf("%f\n", dist);
		if (dist <= 20)
			collobj(obj, data);
		obj = obj->next;
	}
}
