/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:45:19 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 12:06:57 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		set_center(t_fdot *center, t_fdot min, t_fdot max)
{
	center->x = (max.x * 0.5) + min.x;
	center->y = (max.y * 0.5) + min.y;
	center->z = (max.z * 0.5) + min.z;
}

void		rotate_obj1(t_poly *tmp, t_fdot *min, t_fdot *max)
{
	int i;

	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			if (tmp->dot[i].x > max->x)
				max->x = tmp->dot[i].x;
			if (tmp->dot[i].y > max->y)
				max->y = tmp->dot[i].y;
			if (tmp->dot[i].z > max->z)
				max->z = tmp->dot[i].z;
			if (tmp->dot[i].x < min->x)
				min->x = tmp->dot[i].x;
			if (tmp->dot[i].y < min->y)
				min->y = tmp->dot[i].y;
			if (tmp->dot[i].z < min->z)
				min->z = tmp->dot[i].z;
		}
		tmp = tmp->next;
	}
}

void		rotate_obj3(t_poly *tmp, t_object *new)
{
	int i;

	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			tmp->dot[i].x *= new->scale;
			tmp->dot[i].y *= new->scale;
			tmp->dot[i].z *= new->scale;
			tmp->dot[i].x += new->pos.x;
			tmp->dot[i].y += new->pos.y;
			tmp->dot[i].z += new->pos.z;
		}
		tmp = tmp->next;
	}
}

void		rotate_obj2(t_object *new, t_poly *tmp, t_fdot center)
{
	int i;

	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			tmp->dot[i] = rotx(tmp->dot[i], new->rot.x);
			tmp->dot[i] = roty(tmp->dot[i], new->rot.y);
			tmp->dot[i] = rotz(tmp->dot[i], new->rot.z);
			tmp->dot[i].x += center.x;
			tmp->dot[i].y += center.y;
			tmp->dot[i].z += center.z;
		}
		tmp->normale = rotx(tmp->normale, new->rot.x);
		tmp->normale = roty(tmp->normale, new->rot.y);
		tmp->normale = rotz(tmp->normale, new->rot.z);
		tmp = tmp->next;
	}
	tmp = new->poly;
	rotate_obj3(tmp, new);
}

void		rotate_obj(t_object *new)
{
	t_poly	*tmp;
	t_fdot	min;
	t_fdot	max;
	t_fdot	center;
	int		i;

	tmp = new->poly;
	min = (t_fdot){INFINITY, INFINITY, INFINITY};
	max = (t_fdot){-INFINITY, -INFINITY, -INFINITY};
	rotate_obj1(tmp, &min, &max);
	new->dist = get3ddist(max, (t_fdot){.x = 0, .y = 0, .z = 0}) * new->scale;
	set_center(&center, min, max);
	while (tmp)
	{
		i = -1;
		while (++i < 3)
		{
			tmp->dot[i].x -= center.x;
			tmp->dot[i].y -= center.y;
			tmp->dot[i].z -= center.z;
		}
		tmp = tmp->next;
	}
	tmp = new->poly;
	rotate_obj2(new, tmp, center);
}
