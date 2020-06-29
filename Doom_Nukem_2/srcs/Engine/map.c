/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:42:01 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/29 18:52:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	rev_moove(t_input *data, int way)
{
	if (way == KEY_UP)
		mapmoveallp(data, (t_fdot){.x = 8 * data->speed, .y = 0, .z = 0});
	if (way == KEY_DOWN)
		mapmoveallp(data, (t_fdot){.x = -8 * data->speed, .y = 0, .z = 0});
	if (way == KEY_RIGHT)
		mapmoveallp(data, (t_fdot){.x = 0, .y = 8 * data->speed, .z = 0});
	if (way == KEY_LEFT)
		mapmoveallp(data, (t_fdot){.x = 0, .y = -8 * data->speed, .z = 0});
	if (way == 1)
		mapmoveallp(data, (t_fdot){.x = 0, .y = 0, .z = -5});
	if (way == KEY_SPACEBAR)
		mapmoveallp(data, (t_fdot){.x = 0, .y = 0, .z = 8});
}

void	moove(t_input *data, int way)
{
	if (way == KEY_UP)
		mapmoveallp(data, (t_fdot){.x = -8 * data->speed,
		.y = 0, .z = -1});
	if (way == KEY_DOWN)
		mapmoveallp(data, (t_fdot){.x = 8 * data->speed,
		.y = 0, .z = -1});
	if (way == KEY_RIGHT)
		mapmoveallp(data, (t_fdot){.x = 0, .y = -8 * data->speed, .z = -1});
	if (way == KEY_LEFT)
		mapmoveallp(data, (t_fdot){.x = 0, .y = 8 * data->speed, .z = -1});
	if (way == 1)
		mapmoveallp(data, (t_fdot){.x = 0, .y = 0, .z = 5});
	if (way == KEY_SPACEBAR)
		mapmoveallp(data, (t_fdot){.x = 0, .y = 0, .z = -8});
	if (check_colli(data->map))
		rev_moove(data, way);
	chckdoorcolli(way, data->obj, data);
}

void	mapmoveallp(t_input *data, t_fdot way)
{
	t_object *obj;

	obj = data->obj;
	mapmovep(data->map, way);
	while (obj)
	{
		mapmovep(obj->poly, way);
		obj->pos.x += way.x;
		obj->pos.y += way.y;
		obj->pos.z += way.z;
		obj->posrx.x += way.x;
		obj->posrx.y += way.y;
		obj->posrx.z += way.z;
		obj = obj->next;
	}
}

void	mapmovep(t_poly *poly, t_fdot incr)
{
	int		i;
	t_poly	*gones;

	gones = poly;
	while (gones)
	{
		i = -1;
		while (++i < 3)
		{
			gones->dot[i].x += incr.x;
			gones->dot[i].y += incr.y;
			gones->dot[i].z += incr.z;
			gones->rotx[i].x += incr.x;
			gones->rotx[i].y += incr.y;
			gones->rotx[i].z += incr.z;
		}
		gones->d = -(gones->a * gones->dot[0].x + gones->b *
		gones->dot[0].y + gones->c * gones->dot[0].z);
		gones = gones->next;
	}
}

void	rot_sky(t_input *data, t_fdot rot)
{
	if (rot.y)
	{
		data->sky.i = data->angley == 0 ? data->sky.veci :
		applymatpoint(define_yrotmax(data->angley), data->sky.veci);
		data->sky.j = data->angley == 0 ? data->sky.vecj :
		applymatpoint(define_yrotmax(data->angley), data->sky.vecj);
	}
	else
	{
		if (rot.z == 1)
		{
			data->sky.veci = applymatpoint(data->rotz, data->sky.veci);
			data->sky.vecj = applymatpoint(data->rotz, data->sky.vecj);
		}
		else if (rot.z == -1)
		{
			data->sky.veci = applymatpoint(data->minrotz, data->sky.veci);
			data->sky.vecj = applymatpoint(data->minrotz, data->sky.vecj);
		}
	}
}
