/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:34:19 by mwaterso          #+#    #+#             */
/*   Updated: 2020/06/26 18:08:34 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_fdot	getnew_point(t_fdot frst_point, t_fdot scd_point)
{
	t_fdot a;

	a.y = (scd_point.y - frst_point.y) * ((1 - frst_point.x) /
	(scd_point.x - frst_point.x)) + frst_point.y;
	a.z = (scd_point.z - frst_point.z) * ((1 - frst_point.x) /
	(scd_point.x - frst_point.x)) + frst_point.z;
	a.x = 1;
	return (a);
}

t_fdot	normalise_vec(t_fdot a)
{
	float magn;

	magn = magnitude(a);
	return ((t_fdot){.x = a.x / magn, .y = a.y / magn, .z = a.z / magn});
}

int		get_skytex(t_ray ray, t_sphere s)
{
	t_fdot	col;
	float	u;
	float	v;
	float	tmp;

	col = normalise_vec((t_fdot){ray.x, ray.y, ray.z});
	tmp = acos(-scale(s.i, col));
	v = tmp / 3.14;
	tmp = scale(col, s.j) / sin(tmp);
	if (tmp < -1.0f)
		tmp = -1.0f;
	tmp = ((float)acos(tmp)) / 6.28;
	u = tmp;
	u = scale(vectoriel_product(s.i, s.j), col) > 0 ? tmp : 1 - tmp;
	if (u < 0)
		u = 0;
	if (checkzero(u - 1, 0.000005))
		u = 0;
	v = (checkzero(v - 1, 0.000005) ? 0 : 1 - v);
	if (v < 0 || v > 1 | u < 0 || u > 1 || u != u || v != v ||
	__isnanf(u) || __isnanf(v))
		return (0xFF);
	return (s.tex.img[(int)(u * s.tex.width) + (int)((int)(v * s.tex.height) *
	s.tex.width)]);
}

void	get_sky(t_input *data)
{
	int i;

	i = -1;
	while (++i < data->screensize)
		if (data->rays[i].distcolli == -1)
			data->im.tab[i] = get_skytex(data->rays[i], data->sky);
}

void	separate_points(t_poly *map)
{
	t_index index;
	t_fdot	tmp;

	index = (t_index){.i = 0, .k = 0, .j = -1};
	map->nbr_pprojx = 0;
	while (++index.j < 3)
	{
		index.k = (index.j == 2 ? 0 : index.j + 1);
		if (map->dot[index.j].x > 0 && map->dot[index.k].x > 0)
			map->projx[index.i++] = map->dot[index.j];
		else if (map->dot[index.j].x > 0 && map->dot[index.k].x <= 0)
		{
			map->projx[index.i++] = map->dot[index.j];
			tmp = getnew_point(map->dot[index.j], map->dot[index.k]);
			map->projx[index.i++] = tmp;
		}
		else if (map->dot[index.j].x <= 0 && map->dot[index.k].x > 0)
		{
			tmp = getnew_point(map->dot[index.k], map->dot[index.j]);
			map->projx[index.i++] = tmp;
		}
	}
	map->nbr_pprojx = index.i;
}
