/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:40:16 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/29 19:05:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	printobj(t_object *obj, t_input *data)
{
	int		i;
	int		ret;
	t_poly	*po;

	i = -1;
	po = obj->poly;
	while (po)
	{
		i++;
		separate_points(po);
		ret = projxy(po, data);
		if (ret)
		{
			po->isvisible = 1;
			poly_toboxes(data, po);
		}
		else
			po->isvisible = 0;
		po = po->next;
	}
}

int		damage_mob(t_object *obj)
{
	if (obj->type != ENEMI)
		return (0);
	obj->hp -= 10;
	if (obj->hp <= 0)
		obj->exist = 0;
	return (1);
}

void	get_objpo(t_object *objects, t_input *data)
{
	int	i;

	i = -1;
	while (objects)
	{
		while (objects && !objects->exist)
			objects = objects->next;
		if (!objects)
			return ;
		++i;
		printobj(objects, data);
		thread_start(data, objects->poly);
		objects = objects->next;
	}
}
